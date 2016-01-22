
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


#ifndef CESSNASKYHAWK_H_INPUT
#define CESSNASKYHAWK_H_INPUT

#include <GL\glut.h>
#include  "globals.h"
#include  "splash.h"
namespace nsCessna
{



	void reset(void)
	{
		theta[0] = 0;// reset plane to original position
		theta[2] = 0;
		updownspeed = 0;
		turnspeed = 0;

	}



	// mouse callback function



	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void mouse(int btn, int state, int x, int y)
	{
		if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) yaw0 = 1; // if left mouse pressed, change yaw
		if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP) yaw0 = 0; // if left mouse released, stop changing yaw
		if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) yaw1 = 1; // if right mouse pressed, change yaw
		if(btn == GLUT_RIGHT_BUTTON && state == GLUT_UP) yaw1 = 0; // if right mouse released, stop changing yaw
		glutPostRedisplay();
	}



	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	int mouseX, mouseY;		// mouse coordinates
	int oldMouseX, oldMouseY;


	void motion(int x, int y)
	{


		oldMouseX = mouseX;
		oldMouseY = mouseY;
		mouseX = x;
		mouseY = y;


	//	printf("[%d x %d]  \n",oldMouseX,oldMouseY);
	//	printf("[%d x %d]  \n",mouseX,mouseY);

	if (speed>0)
	{
		if ((mouseX - oldMouseX) > 0) theta[2] += 4.0;		// mouse moved to the right
		else if ((mouseX - oldMouseX) < 0) theta[2] -= 4.0;	// mouse moved to the left



		if ((mouseY - oldMouseY) < 0)
		{
			theta[0] += 3.0; // pitch down on s
			updownspeed -= 1;

		}
		else if ((mouseY - oldMouseY) > 0) 	// mouse moved to the left
		{
			theta[0] -= 3.0; // pitch up on X
			updownspeed += 1;

		}



	}
		//printf(" [%d , %d] ",x,y);

	/*
		if(())
		{
		  printf("Left");
		}

		*/
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void passive(int x /*, int y*/)
	{

	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void keyboard_s (int key, int x, int y)
	{
	kbCode=key;
		switch (key)
		{
			/*



			case GLUT_KEY_F1:			break;
			case GLUT_KEY_F2:			break;
			case GLUT_KEY_F3:			break;
			case GLUT_KEY_F4:			break;
			case GLUT_KEY_F5:			break;
			case GLUT_KEY_F6:			break;
			case GLUT_KEY_F7:			break;
			case GLUT_KEY_F8:			break;
			case GLUT_KEY_F9:			break;
			case GLUT_KEY_F10:			break;
			case GLUT_KEY_F11:			break;
			case GLUT_KEY_F12:			break;

			case GLUT_KEY_LEFT:			break;
			case GLUT_KEY_UP:			break;
			case GLUT_KEY_RIGHT:		break;
			case GLUT_KEY_DOWN:			break;

			case GLUT_KEY_PAGE_UP:		break;
			case GLUT_KEY_PAGE_DOWN:	break;

			case GLUT_KEY_HOME:			break;
			case GLUT_KEY_END:			break;
			case GLUT_KEY_INSERT:		break;
			case GLUT_KEY_DELETE:		break;

			*/


			case GLUT_KEY_UP:
			theta[0] += 2.0; // pitch down on s
			updownspeed -= 1;

			break;
			case GLUT_KEY_DOWN:
			theta[0] -= 2.0; // pitch up on X
			updownspeed += 1;

			break;
			case GLUT_KEY_LEFT:
				if (speed>0) theta[2] -= 2.0; // roll left on z
			break;
			case GLUT_KEY_RIGHT:
				if (speed>0) theta[2] += 2.0; // roll right on c
			break;
		}
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	/*


	void keyboard(unsigned char key, int x, int y)
	{
	  if (key == 27)
		exit(0);
	}


		Respond to the mouse events.


	void mouse(int button, int state, int x, int y)
	{
	  mousex = x;
	  mousey = (glutGet(GLUT_WINDOW_HEIGHT) - y);

	  if (button == GLUT_LEFT_BUTTON)
		effect->click(mousex, mousey, state == GLUT_DOWN);
	}


		Follow the mouse around.


	void motion(int x, int y)
	{
	  mousex = x;
	  mousey = (glutGet(GLUT_WINDOW_HEIGHT) - y);
	}



	*/

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	// keyboard callback function


	void key(unsigned char k, int xx, int yy)
	{
		kbCode=k;
		switch(k)
		{
			case 27:
			  exit(0);
			break;

			case 'c':
				theta[2] += 2.0; // roll right on c
			break;

			case 'z':
				theta[2] -= 2.0; // roll left on z
			break;
			case 's':
				theta[0] += 2.0; // pitch down on s
				updownspeed -= 1;
			break;

			case 'x':
				theta[0] -= 2.0; // pitch up on X
				updownspeed += 1;
			break;

			case 'r':
				reset();
			break;

			case 'q':
				exit(1);
			break;

			case '+':
				if (propvar < 2) propvar = 2; // sets propvar to 2 from 0
				propvar +=10; // adds 10

			break;

			case '-':
				propvar -=10; // decrese speed by 10
				if (propvar < 0){propvar = 0; 	reset();   }
			break;

			case '1':
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

			case '2':
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

			case '3':
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

			case '4':
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

			case '5':
				floatcamera = 1;
			break;

			case '6':
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

			case 'j':
			   eyex -= 10;
			break;
			case 'l':
				eyex += 10;
			break;
			case 'i':
				eyey += 10;
			break;
			case 'k':
				eyey -= 10;
			break;
			case 'u':
				eyez += 10;
			break;

			case 'n':
				atx += 10;
			break;

			case 'm':
				atx -= 10;
			break;


		}//switch


		// checks to see if the plane has exceeded maximum pitch or roll
		if( theta[0] > 360.0 ) theta[0] -= 360.0;
		if( theta[0] < -360.0 ) theta[0] += 360.0;
		if( theta[2] > 360.0 ) theta[2] -= 360.0;
		if( theta[2] < -360.0 ) theta[2] += 360.0;

		glutPostRedisplay();
	}




	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	/*


	btn
	#define GLUT_LEFT_BUTTON		0
	#define GLUT_MIDDLE_BUTTON		1
	#define GLUT_RIGHT_BUTTON		2

	state
	#define GLUT_DOWN			0
	#define GLUT_UP				1

	*/





	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	// keyboard function for the splash screen window



	void splashkey(unsigned char k, int xx, int yy)
	{
		glutSetWindow(mainwindow);
		if(k == ' ') glutDestroyWindow(splashscreen);// spacebar will destroy the splashscreen window
		glutPostRedisplay();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	// idle callback for the splash screen window
	void splashidle(void)
	{
		showtext(); // shows the display text function
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

}

#endif CESSNASKYHAWK_H_INPUT
