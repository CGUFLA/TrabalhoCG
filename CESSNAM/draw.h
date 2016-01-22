
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

#ifndef CESSNASKYHAWK_H_DRAW
#define CESSNASKYHAWK_H_DRAW

#include  "globals.h"
namespace nsCessna
{



	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	//previous function gives this kind of roof with 100 steps to the top
	////////*////////////////////////////////*/
	///////*//////////////////////////////////*/
	//////*////////////////////////////////////*/
	/////*//////////////////////////////////////*/
	////*////////////////////////////////////////*/
	///*//////////////////////////////////////////*/
	//*////////////////////////////////////////////*/
	/*//////////////////////////////////////////////*/


	//drawing functions
	//Key to function names draw[partname]()
	//functions contain function calls to the polygon functions and the numbers of the verticies in the
	//arrays specified within those functions.

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawnose()
	{
		nosepolygon4(0,1,2,3);
		nosepolygon3(0,1,4);
		nosepolygon3(1,2,4);
		nosepolygon3(2,3,4);
		nosepolygon3(3,0,4);
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawprop()
	{
		proppolygon4(0,1,2,3);
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawstruts()
	{
		strutspolygon4(0,1,2,3);
		strutspolygon4(4,5,6,7);
		strutspolygon4(0,1,4,5);
		strutspolygon4(1,2,5,6);
		strutspolygon4(2,3,6,7);
		strutspolygon4(3,0,7,4);
		strutspolygon4(8,9,10,11);
		strutspolygon4(12,13,14,15);
		strutspolygon4(8,9,12,13);
		strutspolygon4(9,10,13,14);
		strutspolygon4(10,11,14,15);
		strutspolygon4(11,8,15,12);

	}
	// **********************************************************************
	// *                                                                    *
	// **********************************************************************




	void drawnosegear()
	{
		nosegearpolygon4(0,1,2,3);
		nosegearpolygon4(4,5,6,7);
		nosegearpolygon4(0,1,4,5);
		nosegearpolygon4(1,2,5,6);
		nosegearpolygon4(2,3,6,7);
		nosegearpolygon4(3,0,7,4);
		nosegearpolygon6(8,9,10,11,12,13);
		nosegearpolygon6(14,15,16,17,18,19);
		nosegearpolygon4(8,9,15,14);
		nosegearpolygon4(9,10,16,15);
		nosegearpolygon4(10,11,17,16);
		nosegearpolygon4(11,12,18,17);
		nosegearpolygon4(12,13,19,18);
		nosegearpolygon4(13,8,14,19);

	}
	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawlandinggears()
	{
		llandingpolygon4(0,1,3,2);
		llandingpolygon4(4,5,7,6);
		llandingpolygon4(0,1,7,6);
		llandingpolygon4(2,3,5,4);
		llandingpolygon4(1,7,5,3);
		llandingpolygon4(0,6,4,2);
		llandingpolygon6(8,9,10,11,12,13);
		llandingpolygon6(14,15,16,17,18,19);
		llandingpolygon4(8,9,15,14);
		llandingpolygon4(9,10,16,15);
		llandingpolygon4(10,11,17,16);
		llandingpolygon4(11,12,18,17);
		llandingpolygon4(12,13,19,18);
		llandingpolygon4(13,8,14,19);
		rlandingpolygon4(0,1,3,2);
		rlandingpolygon4(4,5,7,6);
		rlandingpolygon4(0,1,7,6);
		rlandingpolygon4(2,3,5,4);
		rlandingpolygon4(1,7,5,3);
		rlandingpolygon4(0,6,4,2);
		rlandingpolygon6(8,9,10,11,12,13);
		rlandingpolygon6(14,15,16,17,18,19);
		rlandingpolygon4(8,9,15,14);
		rlandingpolygon4(9,10,16,15);
		rlandingpolygon4(10,11,17,16);
		rlandingpolygon4(11,12,18,17);
		rlandingpolygon4(12,13,19,18);
		rlandingpolygon4(13,8,14,19);

	}
	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawbody()
	{
		lbodypolygon5(5,6,7,8,9);
		lbodypolygon5(9, 10, 13, 4, 5);
		lbodypolygon3(10,3,13);
		lbodypolygon5(10, 11, 12, 2, 3);
		lbodypolygon4(12,2,1,0);
		rbodypolygon5(5,6,7,8,9);
		rbodypolygon5(9, 10, 13, 4, 5);
		rbodypolygon3(10,3,13);
		rbodypolygon5(10, 11, 12, 2, 3);
		rbodypolygon4(12,2,1,0);
		whitematerial();
		//rlbodypolygon4(4, 5); // where the window was
		bluematerial();
		rlbodypolygon4(5, 6);
		rlbodypolygon4(6,7);
		rlbodypolygon4(7,8);
		rlbodypolygon4(8,9);
		rlbodypolygon4(9,10);
		rlbodypolygon4(10,11);
		rlbodypolygon4(11,12);
		rlbodypolygon4(12, 0);
		rlbodypolygon4(0,1);
		rlbodypolygon4(1,2);
		rlbodypolygon4(2,3);
		whitematerial();
		//rlbodypolygon4(3,13); // where the back window was
		bluematerial();
		rlbodypolygon4(13,4);


	}




	void drawwings()
	{
		glBegin(GL_POLYGON);
		glVertex3fv(wings[2]);
		glVertex3fv(wings[1]);
		glVertex3fv(wings[0]);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3fv(wings[5]);
		glVertex3fv(wings[4]);
		glVertex3fv(wings[3]);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3fv(wings[1]);
		glVertex3fv(wings[4]);
		glVertex3fv(wings[3]);
		glVertex3fv(wings[0]);
		glEnd();


   		if (notrun){ // if it is the first time loading the image into the image pointer
			//image = glmReadPPM("hiramlogo.ppm", &iwidth, &iheight); // load the image
			//wingtexture(); // call the texturing function
			notrun = 0; // change the flag so that it is no longer reloaded everytime the wing is rendered
		}


		glEnable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex3fv(wings[1]);
		glTexCoord2f(0, 0);
		glVertex3fv(wings[6]);
		glTexCoord2f(0, 1);
		glVertex3fv(wings[7]);
		glTexCoord2f(1, 1);
		glVertex3fv(wings[2]);
		glEnd();

		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex3fv(wings[8]);
		glTexCoord2f(0, 0);
		glVertex3fv(wings[4]);
		glTexCoord2f(0, 1);
		glVertex3fv(wings[5]);
		glTexCoord2f(1, 1);
		glVertex3fv(wings[9]);
		glEnd();

		glDisable(GL_TEXTURE_2D);

		glBegin(GL_POLYGON);
		glVertex3fv(wings[6]);
		glVertex3fv(wings[8]);
		glVertex3fv(wings[9]);
		glVertex3fv(wings[7]);
		glEnd();


		glBegin(GL_POLYGON);
		glVertex3fv(wings[0]);
		glVertex3fv(wings[3]);
		glVertex3fv(wings[5]);
		glVertex3fv(wings[2]);
		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawtailwings()
	{
		glBegin(GL_POLYGON);
		glNormal3fv(normaltailwings[0]);
		glVertex3fv(tailwings[0]);
		glNormal3fv(normaltailwings[1]);
		glVertex3fv(tailwings[1]);
		glNormal3fv(normaltailwings[2]);
		glVertex3fv(tailwings[2]);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3fv(normaltailwings[3]);
		glVertex3fv(tailwings[3]);
		glNormal3fv(normaltailwings[4]);
		glVertex3fv(tailwings[4]);
		glNormal3fv(normaltailwings[5]);
		glVertex3fv(tailwings[5]);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3fv(normaltailwings[0]);
		glVertex3fv(tailwings[0]);
		glNormal3fv(normaltailwings[3]);
		glVertex3fv(tailwings[3]);
		glNormal3fv(normaltailwings[4]);
		glVertex3fv(tailwings[4]);
		glNormal3fv(normaltailwings[1]);
		glVertex3fv(tailwings[1]);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3fv(normaltailwings[1]);
		glVertex3fv(tailwings[1]);
		glNormal3fv(normaltailwings[4]);
		glVertex3fv(tailwings[4]);
		glNormal3fv(normaltailwings[5]);
		glVertex3fv(tailwings[5]);
		glNormal3fv(normaltailwings[2]);
		glVertex3fv(tailwings[2]);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3fv(normaltailwings[2]);
		glVertex3fv(tailwings[2]);
		glNormal3fv(normaltailwings[5]);
		glVertex3fv(tailwings[5]);
		glNormal3fv(normaltailwings[3]);
		glVertex3fv(tailwings[3]);
		glNormal3fv(normaltailwings[0]);
		glVertex3fv(tailwings[0]);
		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************




	void drawground(){
		grassmaterial();
		glBegin(GL_POLYGON);
		glNormal3fv(normalgroundplane[0]);
		glVertex3fv(groundplane[0]);
		glNormal3fv(normalgroundplane[1]);
		glVertex3fv(groundplane[1]);
		glNormal3fv(normalgroundplane[2]);
		glVertex3fv(groundplane[2]);
		glNormal3fv(normalgroundplane[3]);
		glVertex3fv(groundplane[3]);
		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawpillars(){
		for (offset = 0; offset < 1260; offset += 153.5){ // for loop that changes the offset to the pillars are spaced correctly
			glPushMatrix();
			glTranslatef(12.5, 150, 363 + offset); // place and translate by the offset
			glScalef(25, 300, 25);  //size the pillars to the correct specifications
			glutSolidCube(1.0); // create the solid cubes
			glPopMatrix();
		}
		// repetition of above for the other side of the building
		for (offset = 0; offset < 1260; offset += 153.5){
			glPushMatrix();
			glTranslatef(1287.5, 150, 363 + offset);
			glScalef(25, 300, 25);
			glutSolidCube(1.0);
			glPopMatrix();
		}

	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	//drawing the buildings
	//Key to function names:  draw[building]()

	//All of the following functions for the modeling of the buildings are in the basically same fashion
	//glPushMatrix(); to keep the former matrix settings
	//[color]material(); call for the material if changes
	//glTranslatef(. . .); call to place the piece into position
	//glScalef(. . .); call to size the piece correctly
	//glRotatef(. . .); rotation of the piece if needed
	//glutSolidCube(1.0); call to actually create the piece
	//glPopMatrix(); to return to the former matrix settings
	//repeat of the above steps until building is completely modeled
	//various other function calls if necessary

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawmiller(){
		tanmaterial();
		millerpolygon4(0,1,6,7); // three functions calls create the tan colored roof
		millerpolygon4(2,3,4,5);
		millerpolygon4(8,9,10,11);

		redmaterial();
		glPushMatrix();
		glTranslatef(650, 650, 975);
		glScalef(1000,1299,1750);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(650, 797, 975);
		glScalef(1300,999,1250);
		glutSolidCube(1.0);
		glPopMatrix();

		tanmaterial();
		glPushMatrix();
		glTranslatef(603, 50, 14.5);
		glScalef(850, 100, 25);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(165.5, 125, 50);
		glScalef(25, 250, 100);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1137.5, 125, 50);
		glScalef(25, 250, 100);
		glutSolidCube(1.0);
		glPopMatrix();

		drawpillars();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	void drawhenry(){
		tanmaterial();
		henrypolygon4(0,1,6,7);
		henrypolygon4(2,3,4,5);
		henrypolygon4(8,9,10,11);

		redmaterial();
		glPushMatrix();
		glTranslatef(650, 449, 975);
		glScalef(1000,899,1750);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(650, 598, 975);
		glScalef(1300,600,1250);
		glutSolidCube(1.0);
		glPopMatrix();

		tanmaterial();
		glPushMatrix();
		glTranslatef(603, 50, 14.5);
		glScalef(850, 100, 25);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(165.5, 125, 50);
		glScalef(25, 250, 100);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1137.5, 125, 50);
		glScalef(25, 250, 100);
		glutSolidCube(1.0);
		glPopMatrix();

		drawpillars();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	//most of the following building drawing functions are the same as above, except for the following
	//glPushMatrix(); to save the previous matrix
	//glTranslatef(. . .); to put the center where the building should be
	// . . . steps to here like previous building functions
	//glPopMatrix(); returns to the previous matrix

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawBowler(){
		glPushMatrix();
		glTranslatef(5000, -80, 0);
		glPushMatrix();

		redmaterial();
		glTranslatef(500, 600, 4000);
		glScalef(1450,1200,2500);
		glutSolidCube(1.0);

		tanmaterial();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(500, 100,2600);
		glScalef(1450, 200, 300);
		glutSolidCube(1.0);
		glPopMatrix();

		for (bowlersteps = 0; bowlersteps < 10; bowlersteps++){	 // creates 10 steps up to Bowler
			glPushMatrix();
			glTranslatef(500, 10 + 20 * bowlersteps, 2300 + 15 * bowlersteps);
			glScalef(600,20,300 - 30 * bowlersteps);
			glutSolidCube(1.0);
			glPopMatrix();
		}

		glPushMatrix();

		roofmaterial();
		glTranslatef(500, 988, 3660);
		glRotatef(45, 1.0, 0.0, 0.0);
		glScalef(1446,1000,1600);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(500, 500, 2610);
		glRotatef(-15, 1, 0, 0);
		glScalef(1450, 50, 300);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(500, 1200, 2930);
		glScalef(500, 500, 350);
		glRotatef(-45, 0, 0, 1);
		glutSolidCube(1.0);
		glPopMatrix();

		tanmaterial();
		for (bowlerpoles = 0; bowlerpoles < 8; bowlerpoles++){ // creates the poles on the Bowler porch
			if (bowlerpoles == 3) bowlerpoles += 2; // this will skip the middle two poles where there are none
			glPushMatrix();
			glTranslatef(-200 + 200 * bowlerpoles, 330, 2480); // place the poles in the position according to the pole it is on
			glScalef(20, 260, 20); // sizes the pole correctly
			glutSolidCube(1.0); // creates the pole
			glPopMatrix();
		}

		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawGerstackerRoof(){ // function for drawing type of roof that gerstacker features
		int roofsteps; // for incrementing the steps up the roof goes
		roofmaterial();
		for (roofsteps = 0; roofsteps < 101; roofsteps++){ // for loop that increments the roofstep count
			glPushMatrix();
			glTranslatef(0, 1202.5 + 5 * roofsteps, 0); // places in the middle and goes up by 5 for each step up
			glScalef(1450 - 14.5 * roofsteps, 5, 1200 - 5 * roofsteps); // changes the size to be smaller the higher the step
			glutSolidCube(1.0); // creates the steps of the roof
			glPopMatrix();
		}
		redmaterial();
	}


	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawBooth(){
		glPushMatrix();
		glTranslatef(-5500, -80, -1000);
		glPushMatrix();

		redmaterial();
		glTranslatef(0, 600, 0);
		glScalef(1450,1200,5500);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(175, 600, 0);
		glScalef(1800, 1200, 2000);
		glutSolidCube(1.0);
		glPopMatrix();

		roofmaterial();
		glPushMatrix();
		glTranslatef(665, 1200, 0);
		glScalef(800, 600, 1450);
		glRotatef(-45, 1, 0, 0);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(550, 1200, 1800);
		glScalef(300, 300, 450);
		glRotatef(-45, 1, 0, 0);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(550, 1200, -1800);
		glScalef(300, 300, 450);
		glRotatef(-45, 1, 0, 0);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 0);
		glScalef(1, 1, 4.6);
		drawGerstackerRoof(); //puts a Gerstacker type roof on booth
		glPopMatrix();
		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawHinsdale(){
		glPushMatrix();
		glTranslatef(1000, -80, -5000);
		glPushMatrix();

		brownmaterial();
		glTranslatef(0, 1000, 0);
		glScalef(2000,800,4000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 300, 1450);
		glScalef(2000,600,1100);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 300, -1450);
		glScalef(2000,600,1100);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 1600, 0);
		glScalef(2000,400,2000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawTeachout(){
		glPushMatrix();
		glTranslatef(8000, -80, -3000);
		glPushMatrix();
		redmaterial();
		glTranslatef(-850, 600, 0);
		glScalef(1200,1200,2000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(500, 650, 0);
		glScalef(1500,1300,1900);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-750, 800, 1000);
		glScalef(250,800,250);
		glRotatef(90, 1, 0, 0);
		teachoutcyl = gluNewQuadric();
		gluCylinder(teachoutcyl, 1.0, 1.0, 1.0, 30, 30);
		glPopMatrix();
		glPushMatrix();
		roofmaterial();
		glTranslatef(-750, 800, 1000);
		glScalef(250, 1, 250);
		glRotatef(90, 1, 0, 0);
		glutSolidCone(1.0, 1.0, 30, 30);
		glPopMatrix();

		glPopMatrix();
	}
	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawArt(){
		glPushMatrix();
		glTranslatef(9000, -80, -6500);
		glPushMatrix();
		redmaterial();
		glTranslatef(0, 450, 0);
		glScalef(1250,900,2000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 600, -600);
		glScalef(2000,1200,1000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-100, 500, 700);
		glScalef(1800,1000, 800);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();
	}
	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawMusic(){
		glPushMatrix();
		glTranslatef(9000, -80, -9500);
		glPushMatrix();
		redmaterial();
		glTranslatef(0, 600, 0);
		glScalef(1450,1200,2000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 450, -600);
		glScalef(2000,900,800);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawColtonSteps(){ // function will draw the large stairs up to the Colton/Turner building
		int stepsteps; // variable to increment the steps
		for (stepsteps = 0; stepsteps < 25; stepsteps++){ // for loop to create 25 stairs
			glPushMatrix();
			glTranslatef(1000, 5 + 10 * stepsteps, -800 + 10 * stepsteps); // puts the step into correct position
			glScalef(1000 - 10 * stepsteps, 10, 1500 - 10 * stepsteps); // sizes the stairs
			glutSolidCube(1.0); // creates the step
			glPopMatrix();
		}
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawColton(){
		glPushMatrix();
		glTranslatef(5500, -80, -12000);
		glPushMatrix();

		redmaterial();
		glTranslatef(1000, 700, 0);
		glScalef(2000, 1400, 2000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-250, 600, 0);
		glScalef(500, 1200, 1400);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-450, 500, 0);
		glScalef(1500, 1000, 2200);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-1750, 450, 0);
		glScalef(1200, 900, 2400);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();

		tanmaterial();
		glTranslatef(1000, 1320, 0);
		glScalef(2040, 200, 2040);
		glutSolidCube(1.0);
		glPopMatrix();

		drawColtonSteps(); // function call to creat the steps
		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawGerstacker(){
		glPushMatrix();
		glTranslatef(9000, -80, -16000);
		glPushMatrix();

		redmaterial();
		glTranslatef(0, 600, 900);
		glScalef(1450,1200,1200);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 600, -900);
		glScalef(1450,1200,1200);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 750, 0);
		glScalef(1200,900, 600);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 0);
		glScalef(1, 1, 2.5);

		drawGerstackerRoof();
		glPopMatrix();
		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	void drawKennedy(){
		glPushMatrix();
		glTranslatef(-5500, -80, -7500);
		glPushMatrix();

		redmaterial();
		glTranslatef(0, 600, 0);
		glScalef(1450,1200, 3500);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 0);
		glScalef(1, 1, 2.95);

		drawGerstackerRoof();
		glPopMatrix();

		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawQuad(){
		glPushMatrix();
		glTranslatef(-7000, -80, -13000);
		glPushMatrix();

		redmaterial();
		glTranslatef(0, 600, 0);
		glScalef(1450, 1200, 3050);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1525, 600, 2250);
		glScalef(4500, 1200, 1450);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1525, 600, -2250);
		glScalef(4500, 1200, 1450);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(4000, 100, 0);
		glScalef(50, 150, 400);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawBatesRoof(){ // function for drawing type of roof that bates features
		int roofsteps; // for incrementing the steps up the roof goes
		roofmaterial();
		for (roofsteps = 0; roofsteps < 101; roofsteps++){ // for loop that increments the roofstep count
			glPushMatrix();
			glTranslatef(0, 1202.5 + 5 * roofsteps, 0); // places in the middle and goes up by 5 for each step up
			glScalef(4000 - 10 * roofsteps, 5, 4000 - 10 * roofsteps); // changes the size to be smaller the higher the step
			glutSolidCube(1.0); // creates the steps of the roof
			glPopMatrix();
		}
		redmaterial();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawBatesSteps(){ // function will draw the large stairs up to the Bates building
		int stepsteps; // variable to increment the steps
		for (stepsteps = 0; stepsteps < 25; stepsteps++){ // for loop to create 25 stairs
			glPushMatrix();
			glTranslatef(-300 + 20 * stepsteps, 5 + 10 * stepsteps, 0); // puts the step into correct position
			glScalef(600 - 20 * stepsteps, 10, 2000 - 20 * stepsteps); // sizes the stairs
			glutSolidCube(1.0); // creates the step
			glPopMatrix();
		}
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	void drawBates(){
		glPushMatrix();
		glTranslatef(3000, -80, -20000);
		glPushMatrix();

		redmaterial();
		glTranslatef(0, 600, 0);
		glScalef(4000,1200,4000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, 0);
		drawBatesRoof();
		glPopMatrix();
		tanmaterial();
		glPushMatrix();
		glTranslatef(-2000, 0, 0);
		drawBatesSteps();
		glPopMatrix();
		glPopMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void drawLibrary(){
		glPushMatrix();
		glTranslatef(7000, -80, -25000);
		glPushMatrix();

		redmaterial();
		glTranslatef(0, 1000, 0);
		glScalef(4000,2000,4000);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-3500, 700, 0);
		glScalef(3000,1400,2500);
		glutSolidCube(1.0);
		glPopMatrix();

		glPopMatrix();
	}

	// end of building drawing functions


	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	// will draw the roads 10 thick
	// in same sort of position, size, draw type of manner as the buildings

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void drawStreets(){
		glPushMatrix();
		glTranslatef(0,-80,0);
		glPushMatrix();
		roofmaterial();
		glTranslatef(6100, 5, -800);
		glScalef(14800, 10, 1500);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(11000, 5, -10250);
		glScalef(1500, 10, 20400);
		glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-2000, 5, -8250);
		glScalef(1500, 10, 25400);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();
	}

	// End of drawing functions
}
#endif CESSNASKYHAWK_H_DRAW
