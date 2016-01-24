
// *********************************************************************
// *     This software is made available only to individuals and only  *
// *     for educational purposes. Any and all commercial use is       *
// *     stricly prohibited.                                           *
// *********************************************************************
//**********************************************************************
//* Disclaimer: Any borrowed code used in this                         *
//*             program is the property of the                         *
//*             code originator. credit to them.                       *
//*                                                                    *
//*                                                                    *
//*   Unfinished                                                       *
//*   WARNING:                                                         *
//*                                                                    *
//*                                                                    *
//*                                                                    *
//**********************************************************************


namespace nsCessna
{

    int mouseX, mouseY;     // coordenada do mouse
    int oldMouseX, oldMouseY;

	void reset(void)
	{
		theta[0] = 0;// volta o aviao para a posicao original
		theta[2] = 0;
		updownspeed = 0;
		turnspeed = 0;

	}

    // funcao callback do mouse
	void motion(int x, int y)
	{
		oldMouseX = mouseX;
		oldMouseY = mouseY;
		mouseX = x;
		mouseY = y;

    	if (speed>0)
    	{
    		if ((mouseX - oldMouseX) > 0) theta[2] += 0.3;		// mouse move para a direita
    		else if ((mouseX - oldMouseX) < 0) theta[2] -= 0.3;	// mouse move para a esquerda



    		if ((mouseY - oldMouseY) < 0)
    		{
    			theta[0] += 0.3; // move para baixo
    			updownspeed -= 0.2;

    		}
    		else if ((mouseY - oldMouseY) > 0) 	// mouse move para a esquerda
    		{
    			theta[0] -=  0.3; // move para cima
    			updownspeed += 0.2;

    		}

    	}
	}



    // Funcao callback das teclas UP, DOWN, RIGHT, LEFT
	void keyboard_s (int key, int x, int y)
	{
		switch (key)
		{	case GLUT_KEY_DOWN:
    			theta[0] -= 1.0; // aponta para cima
    			updownspeed += 0.5;

    			break;
			case GLUT_KEY_UP:
    			theta[0] += 1.0; // aponta para baixo
    			updownspeed -= 0.5;

    			break;
			case GLUT_KEY_LEFT:
				if (speed>0) theta[2] -= 1.0; // vai para a esquerda
			    break;
			case GLUT_KEY_RIGHT:
				if (speed>0) theta[2] += 1.0; // vai para a direita
			    break;
		}
	}


	// funcao callback do teclado alfanumerico
	void key(unsigned char k, int xx, int yy)
	{
		switch(k)
		{
			case 27:  //tecla ESC
			  exit(0);
			  break;

			case 'd':
				theta[2] += 1.0; // vai para a direita
			    break;

			case 'a':
				theta[2] -= 1.0; // vai para a esquerda
			    break;
			case 'w':
				theta[0] += 1.0; // vai para baixo
				updownspeed -= 0.5;
			    break;

			case 's':
				theta[0] -= 1.0; // vai para cima
				updownspeed += 0.5;
			    break;

			case 'r':
				reset();
			    break;

			case 'q':
				exit(0);
			    break;

			case '+':
				if (propvar < 2) propvar = 2; // aumenta a velocidade da helice em 2 se 0
				propvar +=10; // aumenta a velocidade da helice em 10

			    break;

			case '-':
				propvar -=10; // diminui a velocidade da helice em 10
				if (propvar < 0){propvar = 0; 	reset();   }
			    break;

			case '1': //Camera traseira
				floatcamera = 0;
				insidecamera = 0;
				eyex = 0.0;
				eyey = 110.0;
				eyez = -550.0;
				atx = 0.0;
				aty = 0.0;
				atz = 0.0;
				upx = 0.0;
				upy = 1.0;
				upz = 0.0;

			    break;

			case '2': //Camera lateral direita
				floatcamera = 0;
				insidecamera = 0;
				eyex = 500.0;
				eyey = 1.0;
				eyez = 0.0;
				atx = 0.0;
				aty = 0.0;
				atz = 0.0;
				upy = 1.0;
				upz = 0.0;

			    break;

			case '3': //Camera lateral esquerda
				floatcamera = 0;
				insidecamera = 0;
				eyex = -500.0;
				eyey = 1.0;
				eyez = 0.0;
				atx = 0.0;
				aty = 0.0;
				atz = 0.0;
				upy = 1.0;
				upz = 0.0;

			    break;

			case '4': //Camera interna do aviao
				insidecamera = 1;
				eyex = 0.0;
				eyey = 22.0;
				eyez = 35.0;
				atx = 0.0;
				aty = 22.0;
				atz = 100.0;
				upy = 1.0;
				upz = 0.0;

			    break;

			case '5': //Camera inicial
				floatcamera = 1;
                insidecamera = 1;
                eyex = 0.0;
                eyey = 110.0;
                eyez = -550.0;
                atx = 0.0;
                aty = 0.0;
                atz = 0.0;
                upx = 0.0;
                upy = 1.0;
                upz = 0.0;
			    break;

			case '6': //Camera aerea
				floatcamera = 0;
				insidecamera = 0;
				eyex = 0.0;
				eyey = 500.0;
				eyez = -650.0;
				atx = 0.0;
				aty = 0.0;
				atz = 0.0;
				upy = 1.0;
				upz = 0.0;
			    break;

			case 'j': //Gira a camera do aviao para a direita
			   eyex -= 10;
			   break;
			case 'l': //Gira a camera do aviao para a esquerda
				eyex += 10;
			    break;
			case 'i': //Gira a camera do aviao para cima
				eyey += 10;
			    break;
			case 'k': //Gira a camera do aviao para baixo
				eyey -= 10;
			    break;

			case 'u': //avanca a camera do cenario para frente
				eyez += 10;
			    break;
			case 'n': //Gira a camera da tela para a esquerda
				atx += 10;
			    break;
			case 'm': //Gira a camera da tela para a direita
				atx -= 10;
			    break;


		}//switch

		// checa se alcancou o maximo de rotacao
		if( theta[0] > 360.0 ) theta[0] -= 360.0;
		if( theta[0] < -360.0 ) theta[0] += 360.0;
		if( theta[2] > 360.0 ) theta[2] -= 360.0;
		if( theta[2] < -360.0 ) theta[2] += 360.0;

		glutPostRedisplay(); //Recarrega a janela atual
	}
}

