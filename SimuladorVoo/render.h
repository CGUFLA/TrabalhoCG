namespace nsCessna
{
    void drawairplane();
    void drawgroundandbuildings();

    void display(void) // Funcao display, chama todas as luzes e funcoes de desenho na tela
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );

        if(now->tm_sec % 5 == 0) {
            if(color_ambient > 1.70){
                pos = 1;
            }
            if(color_ambient < -1){
                pos = 0;
            }

            if(pos) {
                red -= 8.0;
                blue -= 11.0;
                green -= 15.0;
                color_ambient -= 0.01;
            }
            else {
                red+= 8.0;
                blue += 11.0;
                green += 15.0;
                color_ambient += + 0.01;
            }
        }


        //valores padrão dos materiais
        GLfloat mat_specular[]={0.0, 0.0, 0.0, 1.0};
        GLfloat mat_diffuse[]={0.5, 0.0, 0.0, 1.0};
        GLfloat mat_ambient[]={0.5, 0.6, 0.7, 1.0};
        GLfloat mat_shininess={32.0};

        // as seguintes configurações são para a iluminação, apenas os dois primeiros estão sendo utilizados
        GLfloat light_ambient[]={color_ambient, color_ambient, color_ambient, 0.0};
        GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular[]={0.0, 0.0, 0.0, 1.0};

        GLfloat global_ambient[]={0.0, 0.0, 0.0, 0.0};

        GLfloat light_ambient1[]={0.1 , 0.1, 0.1, 1.0};
        GLfloat light_diffuse1[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular1[]={1.0, 1.0, 1.0, 1.0};

        //define as variáveis de iluminação para as funções glLight
        //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

        //glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

        //inicia os padrões para os materiais
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

        //seta a luz global ambiente
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

        //permite o sombreamento e módulos de iluminação
        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);

        //glDepthFunc(GL_LEQUAL);
        //permite teste de profundidade para esconder o que há atras dos objetos
        glEnable(GL_DEPTH_TEST);

        //define luz azul para o céu
        glClearColor(red/255.0,blue/255.0,green/255.0,1.0);
        //limpa os buffers para o próximo desenho
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        //define as variáveis de alteração da função lookat
        gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz);

        elevation = elevation + updownspeed; // define a elevação a mudar com a diferença da velocidade

        // funções físicas

        // 1.   Se o avião sobe em um ângulo muito grande, as asas não vai mais conseguir levantar usando
        //Princípio de Bernoulli, porque o ar que viaja através da parte superior da asa é interrompido.
        //Isto irá resultar em uma perda repentina de altitude ou uma queda na inclinação do avião e
        //altitude até as asas novamente começar a criar elevador.
        if (theta[0] < -30){ // se o avião esta subindo a um anglo superior a 30º
            stalling = 1;
        }

        if (theta[0] > 20){ // em seguida irá parar de descer quando chegar a um anglo de -30º
            stalling = 0;
        }

        if (stalling) stallanimate(); // se ele está parado, chama a função de bloqueio


        // 2. Velocidade e elevação. Se o avião não está viajando pelo ar rápido o suficiente, então as asas já não serão
        //capazes de criar sustentação suficiente para equilibrar o peso do avião.
        //Isto irá criar uma inclinação gradual de campo e atitude dependendo de quão rápido o avião está se movendo.
        //Começando lentamente, em seguida, mais rápido ele vai caindo.
        //Isso continuará até que o avião começa a se mover rápido o suficiente novamente para obter sustentação suficiente.
        if (propvar < 60 && propvar != 0){ // se o avião não se move rápido o suficiente
            updownspeed -= (30/propvar) * 0.1; // ele começa a perder altitude
            theta[0] += 2 * (30.0/propvar) * 0.1; // bem como perder campo
            if (theta[0] > 90) theta[0] = 90; // continuará indo para baixo se estiver descendo
        }

        // 3. Atravessar o chão: Um avião não pode ir até o chão.
        //Esta é uma detecção de colisão muito simples com o solo,
        //basicamente, se ele tenta obter uma altitude negativa, então ele simplesmente permanece em zero,
        //o plano se torna nível.

        if (elevation <= 0){ // se o avião tenta penetrar o chão
            elevation = 0;// ele irá retornar para o nível 0
            updownspeed = 0; // ele não terá variação de velocidade
            printf("%.2f\n", propvar);
            if(propvar >= 0) {
                theta[0] -= 0.2;
                propvar -= 0.2;
            }
            if(propvar < 0) {
                theta[1] = -90.00;
                propvar = 0;
            }
            theta[0] = 0;
        }

        // 4.  Take-off. O avião não pode decolar até que uma velocidade mínima seja alcançada
        // para criar sustentação suficiente para tirá-lo do chão.
        //Isso mantém o avião no solo até que a velocidade necessária seja alcançada.
        if (elevation < 10){ //se tentar se levantar do chão
            if (propvar < 60){ // e não tiver atingido a velocidade minima
                theta[0] = 0; // ele não irá subir
                elevation = 0; // ele irá permanecer no chão
                updownspeed = 0; // essa ação nãoa carretará em alteração da velocidade
            }
        }

        // 5.  Sem força. Se o avião está sem força irá despencar
        if (propvar == 0 && elevation != 0){ // Se a helice não está girando e o avião está no ar
            elevation -= 30; // a altitude cai significativamente
            theta[0] += 3; // irá perder altura rapidamente
            if (theta[0] > 90) theta[0] = 90; // irá ser atraído para o chão
        }

        //se esta dentro do aviao
        if (insidecamera == 1){ // ajustar a camera para o movimento do avião
        glRotatef(theta[0], -1.0, 0.0, 0.0); // chamadas de funções de rotação
        glRotatef(planeyaw, 0.0, 1.0, 0.0);
        glRotatef(theta[2], 0.0, 0.0, -1.0);
        }

        glRotatef(theta[1], 0.0, 1.0, 0.0); // rotaciona o chão e as construções em torno de y

        glTranslatef(sidewayspos, -elevation, -forwardpos);

        drawgroundandbuildings(); // chama função de desenho para chão e edificios

        glLoadIdentity();

        gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz); // seta configurações da camera para a nova identidade

        if (insidecamera == 0) {
            glRotatef(theta[0], 1.0, 0.0, 0.0); // Chamadas de rotação
            glRotatef(planeyaw, 0.0, 1.0, 0.0);
            glRotatef(theta[2], 0.0, 0.0, 1.0);
        }

        drawairplane(); // desenha o avião

    //#ifdef DEBUG
        gotoxy(1 ,3 );printf("Angulo do Leme %.02f",theta[0]);
        gotoxy(32,3 );printf("Angulo do Cenario %.02f",theta[1]);

        gotoxy(1,5 );printf("Inclinacao do Aviao %.02f",theta[2]);

        gotoxy(32,5 );printf("Velocidade Inclinacao %.02f",turnspeed);

        gotoxy(1 ,7 );printf("Angulo da Helice %.02f",propspin);
        gotoxy(32,7 );printf("Velocidade da Helice %.02f",propvar);
        gotoxy(1 ,9 );printf("Elevacao %.02f",elevation);

        gotoxy(1 ,11 );printf("Velocidade do Aviao %.02f",speed);

        gotoxy(1 ,16 );printf("Velocidade Minima para Decolar: 12.40");gotoxy(1 ,21);
    //#endif

    }

    void myReshape(int w, int h)
    {
        glMatrixMode(GL_PROJECTION);
        glViewport(0, 0, w, h);
        glLoadIdentity();
        gluPerspective(55.0, w/h, 1, 15000); // define a perspectiva para uma relação ângulo largura / altura de 55 graus a partir de 1 até 10000
        glMatrixMode(GL_MODELVIEW);
    }


    //funções para desenhar o solo e todos os edificios


    void drawgroundandbuildings()
    {
        drawground();
        drawBowler();
        drawHinsdale();
        drawTeachout();
        drawArt();
        drawMusic();
        drawBooth();
        drawKennedy();
        drawGerstacker();
        drawQuad();
        drawBates();
        drawLibrary();
        drawColton();
        drawStreets();
        glTranslatef(0.0, -80.0, 1000);
        drawmiller();
        glTranslatef(2000.0, 0.0, 1200.0);
        drawmiller();
        glTranslatef(5000.0, 0.0, 0.0);
        drawhenry();
        glPushMatrix();
    }


    // chamada hierarquica para desenhar o avião e a rotação das hélices

    void drawairplane()
    {
        bluematerial(); //seta cor para azul
        drawbody();

        whitematerial(); //seta cor para branco
        drawwings();
        drawtailwings();

        redmaterial(); //seta cor para vermelho
        drawstruts();
        drawlandinggears();
        drawnosegear();
        drawnose();

        whitematerial(); //seta cor para branco
        glTranslatef(0.0,-10.0,0.0); //move hélice no eixo x
        glRotatef(propspin, 0.0,0.0,-1.0); //rotaciona helice no eixo z
        glTranslatef(0.0,10.0,0.0); //move helice
        drawprop();
        glFlush();
        glutSwapBuffers();
        glPopMatrix();

    }


    void wingtexenv(void)
    {
        GLfloat env_color[4], border_color[4];

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, env_color);
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
    }



    void wingtexture(void)
    {
        wingtexenv();
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, iwidth, iheight, GL_RGB, GL_UNSIGNED_BYTE, image);
    }


    void texenv(void)
    {
        GLfloat env_color[4], border_color[4];

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, env_color);
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
    }

    void texture(void)
    {
        texenv();
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, iwidth, iheight, GL_RGB, GL_UNSIGNED_BYTE, image);
    }

}
