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


        //valores padr�o dos materiais
        GLfloat mat_specular[]={0.0, 0.0, 0.0, 1.0};
        GLfloat mat_diffuse[]={0.5, 0.0, 0.0, 1.0};
        GLfloat mat_ambient[]={0.5, 0.6, 0.7, 1.0};
        GLfloat mat_shininess={32.0};

        // as seguintes configura��es s�o para a ilumina��o, apenas os dois primeiros est�o sendo utilizados
        GLfloat light_ambient[]={color_ambient, color_ambient, color_ambient, 0.0};
        GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular[]={0.0, 0.0, 0.0, 1.0};

        GLfloat global_ambient[]={0.0, 0.0, 0.0, 0.0};

        GLfloat light_ambient1[]={0.1 , 0.1, 0.1, 1.0};
        GLfloat light_diffuse1[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular1[]={1.0, 1.0, 1.0, 1.0};

        //define as vari�veis de ilumina��o para as fun��es glLight
        //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

        //glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

        //inicia os padr�es para os materiais
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

        //seta a luz global ambiente
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

        //permite o sombreamento e m�dulos de ilumina��o
        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);

        //glDepthFunc(GL_LEQUAL);
        //permite teste de profundidade para esconder o que h� atras dos objetos
        glEnable(GL_DEPTH_TEST);

        //define luz azul para o c�u
        glClearColor(red/255.0,blue/255.0,green/255.0,1.0);
        //limpa os buffers para o pr�ximo desenho
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        //define as vari�veis de altera��o da fun��o lookat
        gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz);

        elevation = elevation + updownspeed; // define a eleva��o a mudar com a diferen�a da velocidade

        // fun��es f�sicas

        // 1.   Se o avi�o sobe em um �ngulo muito grande, as asas n�o vai mais conseguir levantar usando
        //Princ�pio de Bernoulli, porque o ar que viaja atrav�s da parte superior da asa � interrompido.
        //Isto ir� resultar em uma perda repentina de altitude ou uma queda na inclina��o do avi�o e
        //altitude at� as asas novamente come�ar a criar elevador.
        if (theta[0] < -30){ // se o avi�o esta subindo a um anglo superior a 30�
            stalling = 1;
        }

        if (theta[0] > 20){ // em seguida ir� parar de descer quando chegar a um anglo de -30�
            stalling = 0;
        }

        if (stalling) stallanimate(); // se ele est� parado, chama a fun��o de bloqueio


        // 2. Velocidade e eleva��o. Se o avi�o n�o est� viajando pelo ar r�pido o suficiente, ent�o as asas j� n�o ser�o
        //capazes de criar sustenta��o suficiente para equilibrar o peso do avi�o.
        //Isto ir� criar uma inclina��o gradual de campo e atitude dependendo de qu�o r�pido o avi�o est� se movendo.
        //Come�ando lentamente, em seguida, mais r�pido ele vai caindo.
        //Isso continuar� at� que o avi�o come�a a se mover r�pido o suficiente novamente para obter sustenta��o suficiente.
        if (propvar < 60 && propvar != 0){ // se o avi�o n�o se move r�pido o suficiente
            updownspeed -= (30/propvar) * 0.1; // ele come�a a perder altitude
            theta[0] += 2 * (30.0/propvar) * 0.1; // bem como perder campo
            if (theta[0] > 90) theta[0] = 90; // continuar� indo para baixo se estiver descendo
        }

        // 3. Atravessar o ch�o: Um avi�o n�o pode ir at� o ch�o.
        //Esta � uma detec��o de colis�o muito simples com o solo,
        //basicamente, se ele tenta obter uma altitude negativa, ent�o ele simplesmente permanece em zero,
        //o plano se torna n�vel.

        if (elevation <= 0){ // se o avi�o tenta penetrar o ch�o
            elevation = 0;// ele ir� retornar para o n�vel 0
            updownspeed = 0; // ele n�o ter� varia��o de velocidade
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

        // 4.  Take-off. O avi�o n�o pode decolar at� que uma velocidade m�nima seja alcan�ada
        // para criar sustenta��o suficiente para tir�-lo do ch�o.
        //Isso mant�m o avi�o no solo at� que a velocidade necess�ria seja alcan�ada.
        if (elevation < 10){ //se tentar se levantar do ch�o
            if (propvar < 60){ // e n�o tiver atingido a velocidade minima
                theta[0] = 0; // ele n�o ir� subir
                elevation = 0; // ele ir� permanecer no ch�o
                updownspeed = 0; // essa a��o n�oa carretar� em altera��o da velocidade
            }
        }

        // 5.  Sem for�a. Se o avi�o est� sem for�a ir� despencar
        if (propvar == 0 && elevation != 0){ // Se a helice n�o est� girando e o avi�o est� no ar
            elevation -= 30; // a altitude cai significativamente
            theta[0] += 3; // ir� perder altura rapidamente
            if (theta[0] > 90) theta[0] = 90; // ir� ser atra�do para o ch�o
        }

        //se esta dentro do aviao
        if (insidecamera == 1){ // ajustar a camera para o movimento do avi�o
        glRotatef(theta[0], -1.0, 0.0, 0.0); // chamadas de fun��es de rota��o
        glRotatef(planeyaw, 0.0, 1.0, 0.0);
        glRotatef(theta[2], 0.0, 0.0, -1.0);
        }

        glRotatef(theta[1], 0.0, 1.0, 0.0); // rotaciona o ch�o e as constru��es em torno de y

        glTranslatef(sidewayspos, -elevation, -forwardpos);

        drawgroundandbuildings(); // chama fun��o de desenho para ch�o e edificios

        glLoadIdentity();

        gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz); // seta configura��es da camera para a nova identidade

        if (insidecamera == 0) {
            glRotatef(theta[0], 1.0, 0.0, 0.0); // Chamadas de rota��o
            glRotatef(planeyaw, 0.0, 1.0, 0.0);
            glRotatef(theta[2], 0.0, 0.0, 1.0);
        }

        drawairplane(); // desenha o avi�o

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
        gluPerspective(55.0, w/h, 1, 15000); // define a perspectiva para uma rela��o �ngulo largura / altura de 55 graus a partir de 1 at� 10000
        glMatrixMode(GL_MODELVIEW);
    }


    //fun��es para desenhar o solo e todos os edificios


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


    // chamada hierarquica para desenhar o avi�o e a rota��o das h�lices

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
        glTranslatef(0.0,-10.0,0.0); //move h�lice no eixo x
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
