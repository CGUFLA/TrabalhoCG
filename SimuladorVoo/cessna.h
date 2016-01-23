
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
// *********************************************************************
// *                                                                   *
// *********************************************************************


//		this file is from Nate Robins Texture Tutorial
//      Nate Robins, 1997, 2000
//      nate@pobox.com, http://www.pobox.com/~nate
//		also included in the workspace is Nate Robins glm.c file

#ifndef CESSNASKYHAWK_H
#define CESSNASKYHAWK_H

#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <GL\glut.h>

#include  "glm.h"
#include  "vertices.h"
#include  "materials.h"
#include  "polygons.h"
#include  "draw.h"
#include  "render.h"
#include  "flightdynamics.h"
#include  "globals.h"
#include  "input.h"
#include  "splash.h"

namespace nsCessna
{



	void initSim(void)
	{
		/*	printf("DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG DEBUG\n");
			printf("Flight Simulator for Cessna Skyhawk\n");
			printf("Tutorial\n");
			printf("http://robgotschall.dhs.org/	\n");
			printf("January 20, 2001 - April 3, 2001\n\n");

			printf("GLUT_WINDOW_X	        %d \n",glutGet(GLUT_WINDOW_X));
			printf("GLUT_WINDOW_Y			%d \n",glutGet(GLUT_WINDOW_Y));
			printf("GLUT_WINDOW_WIDTH		%d \n",glutGet(GLUT_WINDOW_WIDTH));
			printf("GLUT_WINDOW_HEIGHT		%d \n",glutGet(GLUT_WINDOW_HEIGHT));
			printf("GLUT_SCREEN_WIDTH		%d \n",glutGet(GLUT_SCREEN_WIDTH));
			printf("GLUT_SCREEN_HEIGH		%d \n\n",glutGet(GLUT_SCREEN_HEIGHT));
			printf("Instructions for use\n");
			printf("Use the x and v keys to control the roll of the plane\n");
			printf("Use the d and c keys to control the pitch of the plane.\n");
			printf("Use the + and - keys to control the speed of the plane.\n");
			printf("Keys 1, 2, 3, 4, and 6 control the different views.\n");
			printf("Key 5 puts into floating camera view \n");
			printf(" j, k, l, u, i, o control the floating camera\n");
			printf("Use the right and left mouse buttons to control the yaw of the plane.\n");
			printf("To reset the plane to original position press the r key.\n");
			printf("To quit press the q key.\n");
	*/

			//glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //utiliza um buffer duplo na criação dos desenhos. O desenho é feito do buffer depth e enviado para o buffer rgb para evitar que haja evitando cintilações
	 		glutInitWindowSize(576, 384); // cria uma janela de tamanho padrão 576 x 384
			mainwindow = glutCreateWindow("Simulador de vôo"); // cria uma janela com o título informado
			//glutInitWindowSize(417, 374); // makes splash screen window
			eyex = 0.0; //seta as posições de visão padrão do sistema
			eyey = 110.0;
			eyez = -550.0;
			atx = 0.0;
			aty = 0.0;
			atz = 0.0;
			upx = 0.0;
			upy = 1.0;
			upz = 0.0;
			//splashscreen = glutCreateWindow(""); // creates the splash creen window
			//glutSetWindow(splashscreen); // names it splashscreen

			//glutPositionWindow(47,60); // positions the window
			//glutKeyboardFunc(splashkey); // sets the splash screen keyboard callback
			glutDisplayFunc(splashdisplay); // seta o callback da tela inicial do jogo
			//	glutIdleFunc(splashidle); // sets the splash screen idle callback
				glEnable(GL_DEPTH_TEST); // ativa o depth test que gerencia o z-buffer, um gerenciador de profundidade para evitar sobreposições
			glutReshapeFunc(myReshape); // seta myReshape como callback para redesenho da tela

			glutSetWindow(mainwindow);
			glutPositionWindow(384,476);
			glutReshapeFunc(myReshape);
			glutKeyboardFunc(key);
			glutSpecialFunc (keyboard_s);
			//glutMotionFunc(motion);
			//glutMouseFunc(mouse); // sets the main mouse callback

			glutPassiveMotionFunc(motion);


			glutDisplayFunc(display); // seta display como a função principal do desenho
			   glutIdleFunc(yaw); // função que irá ser usada quando o sistema estiver ocioso
			   glEnable(GL_DEPTH_TEST);
			   glEnable(GL_NORMALIZE); //para evitar comportamentos erroneos da luminosidade, a função ativa a normalização dos vetores


	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	void runSim(void)
	{
		glutMainLoop(); // faz um loop no sistema para ficar redesenhando sempre até o sistema ser fechado
	}

}

#endif CESSNASKYHAWK_H
