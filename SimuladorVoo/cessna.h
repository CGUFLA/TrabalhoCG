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

			glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //utiliza um buffer duplo na cria��o dos desenhos. O desenho � feito do buffer depth e enviado para o buffer rgb para evitar que haja evitando cintila��es
	 		glutInitWindowSize(576, 384); // cria uma janela de tamanho padr�o 576 x 384
			mainwindow = glutCreateWindow("Simulador de v�o"); // cria uma janela com o t�tulo informado
			eyex = 0.0; //seta as posi��es de vis�o padr�o do sistema
			eyey = 110.0;
			eyez = -550.0;
			atx = 0.0;
			aty = 0.0;
			atz = 0.0;
			upx = 0.0;
			upy = 1.0;
			upz = 0.0;
			
			glutDisplayFunc(splashdisplay); // seta o callback da tela inicial do jogo
				glEnable(GL_DEPTH_TEST); // ativa o depth test que gerencia o z-buffer, um gerenciador de profundidade para evitar sobreposi��es
			glutReshapeFunc(myReshape); // seta myReshape como callback para redesenho da tela

			glutSetWindow(mainwindow);
			glutPositionWindow(384,476);
			glutReshapeFunc(myReshape);
			glutKeyboardFunc(key);
			glutSpecialFunc (keyboard_s);
			glutPassiveMotionFunc(motion);


			glutDisplayFunc(display); // seta display como a fun��o principal do desenho
			   glutIdleFunc(yaw); // fun��o que ir� ser usada quando o sistema estiver ocioso
			   glEnable(GL_DEPTH_TEST);
			   glEnable(GL_NORMALIZE); //para evitar comportamentos erroneos da luminosidade, a fun��o ativa a normaliza��o dos vetores


	}


	void runSim(void)
	{
		glutMainLoop(); // faz um loop no sistema para ficar redesenhando sempre at� o sistema ser fechado
	}

}
