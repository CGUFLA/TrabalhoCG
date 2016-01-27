#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <ctime>
#include <iostream>

#define windowWidth  576
#define windowHeight 384

#include  "globals.h"
#include  "glm.h"
#include  "vertices.h"
#include  "materials.h"
#include  "polygons.h"
#include  "draw.h"
#include  "flightdynamics.h"
#include  "render.h"
#include  "input.h"

namespace nsCessna
{



	void initSim(void) //inicia simulador
	{

			glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //utiliza um buffer duplo na cria��o dos desenhos. O desenho � feito do buffer depth e enviado para o buffer rgb para evitar que haja evitando cintila��es
	 		glutInitWindowSize(windowWidth, windowHeight); // cria uma janela de tamanho padr�o 576 x 384
			mainwindow = glutCreateWindow("Simulador de v�o"); // cria uma janela com o t�tulo informado

			eyex = 0.0; // define as posi��es de vis�o padr�o do sistema
			eyey = 110.0;
			eyez = -550.0;
			atx = 0.0;
			aty = 0.0;
			atz = 0.0;
			upx = 0.0;
			upy = 1.0;
			upz = 0.0;

            ambiente = 0.0;
            pos = 0;
            red = 51.0;
            blue = 189.0;
            green = 255.0;

			glEnable(GL_DEPTH_TEST); // ativa o depth test que gerencia o z-buffer, um gerenciador de profundidade para evitar sobreposi��es

			glutPositionWindow(384,476); //Posiciona a janela no centro da tela
			glutReshapeFunc(myReshape);  // define myReshape como callback para redesenho da tela

			glutKeyboardFunc(key); //define a funcao do teclado alfanumerico
			glutSpecialFunc (keyboard_s); //define a funcao das teclas do teclado de UP, DOWN, RIGHT, LEFT
			glutPassiveMotionFunc(motion); //define a funcao para o mouse

			glutDisplayFunc(display); // define display como a fun��o principal do desenho
			glutIdleFunc(yaw); // fun��o que ir� ser usada quando o sistema estiver ocioso
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_NORMALIZE); //para evitar comportamentos erroneos da luminosidade, a fun��o ativa a normaliza��o dos vetores


	}

	void runSim(void)
	{
		glutMainLoop(); // faz um loop no sistema para ficar redesenhando sempre at� o sistema ser fechado
	}

}
