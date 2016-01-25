#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
#include <math.h>
#include <GL/glut.h>

#include  "globals.h"
#include  "glm.h"
#include  "vertices.h"
#include  "materials.h"
#include  "polygons.h"
#include  "draw.h"
#include  "flightdynamics.h"
#include  "render.h"
#include  "splash.h"
#include  "input.h"

namespace nsCessna
{



	void initSim(void) //inicia simulador
	{

			glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //utiliza um buffer duplo na criação dos desenhos. O desenho é feito do buffer depth e enviado para o buffer rgb para evitar que haja evitando cintilações
	 		glutInitWindowSize(576, 384); // cria uma janela de tamanho padrão 576 x 384
			mainwindow = glutCreateWindow("Simulador de vôo"); // cria uma janela com o título informado
			eyex = 0.0; //seta as posições de visão padrão do sistema
			eyey = 110.0;
			eyez = -550.0;
			atx = 0.0;
			aty = 0.0;
			atz = 0.0;
			upx = 0.0;
			upy = 1.0;
			upz = 0.0;
			
			glutDisplayFunc(splashdisplay); // seta o callback da tela inicial do jogo
				glEnable(GL_DEPTH_TEST); // ativa o depth test que gerencia o z-buffer, um gerenciador de profundidade para evitar sobreposições
			glutReshapeFunc(myReshape); // seta myReshape como callback para redesenho da tela

			glutSetWindow(mainwindow);
			glutPositionWindow(384,476);
			glutReshapeFunc(myReshape);
			glutKeyboardFunc(key);
			glutSpecialFunc (keyboard_s);
			glutPassiveMotionFunc(motion);


			glutDisplayFunc(display); // seta display como a função principal do desenho
			   glutIdleFunc(yaw); // função que irá ser usada quando o sistema estiver ocioso
			   glEnable(GL_DEPTH_TEST);
			   glEnable(GL_NORMALIZE); //para evitar comportamentos erroneos da luminosidade, a função ativa a normalização dos vetores


	}


	void runSim(void)
	{
		glutMainLoop(); // faz um loop no sistema para ficar redesenhando sempre até o sistema ser fechado
	}

}
