
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

namespace nsCessna
{

	// spacebar is array of characters to spell out "Press Spacebar to Continue"
	char spacebar[26] = {'P','r','e','s','s',' ','S','p','a','c','e','b','a','r',' ','t','o',' ','C','o','n','t','i','n','u','e'};
	int j = 0; // to increment through spelling
	static GLfloat theta[] = {0.0,-90.0,0.0};//for spin
	static GLfloat turnspeed = 0.0; // variable for the speed at which the plane will turn
	static GLfloat yaw0 = 0;//for yaw, so mouse can be held down
	static GLfloat yaw1 = 0;
	static GLfloat planeyaw = 0; // gives the angle of the yaw of the plane

	static GLfloat propvar=0; // the speed of the propellor
	static GLfloat elevation = 0; // the height of the plane in repsect to the ground
	static GLfloat updownspeed = 0; // the speed at which the height will change
	static GLfloat speed = 0; // the speed at which the plane will move
	float forwardpos = -350; // the position in the y axis that the plane starts at with respect to the ground
	float sidewayspos = 0; // the position in the x axis that the plane starts at with respect to the ground
	int stalling = 0; // flag for if the plane is in a stall or not

	GLfloat splash[][2] = {{0,0},{0,300},{300,300},{300,0}};

	int mainwindow, splashscreen, rx, ry, i; // variables for the window sizes for resizing
	float eyex, eyey, eyez, atx, aty, atz, upx, upy, upz; // variables for the camera with the glLookAt function
	int floatcamera = 0; // flags to know if in the floating camera
	int insidecamera = 0; // or inside the plane mode
	int bowlerpoles; // variable for spacing and counting the poles on the porch of Bowler
	int bowlersteps; // variable for spacing and counting of steps up to Bowler
	// variables needed for Nate Robins Code for texture mapping ppm files.  See below
	GLint offset = 0;  // counter for placement of the different pillars
	static GLfloat propspin = 0; // gives the angle that the propellor is at
	unsigned char* image = NULL;
	int iheight, iwidth;


	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	}




}
