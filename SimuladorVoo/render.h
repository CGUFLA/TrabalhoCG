
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

// **********************************************************************
// *                                                                    *
// **********************************************************************


namespace nsCessna
{
    void drawairplane();
    void drawgroundandbuildings();

	void display(void) // Funcao display, chama todas as luzes e funcoes de desenho na tela
	{

		//default material values, should not matter once the other material functions are called
		GLfloat mat_specular[]={0.0, 0.0, 0.0, 1.0};
		GLfloat mat_diffuse[]={0.5, 0.0, 0.0, 1.0};
		GLfloat mat_ambient[]={0.5, 0.6, 0.7, 1.0};
		GLfloat mat_shininess={32.0};

		// following variable settings are for the lighting, only the first two are used
		// the last two are optional, this sets up lighting to look more natural
		GLfloat light_ambient[]={0.1, 0.1, 0.1, 1.0};
		GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
		GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
		//GLfloat light_position[]={sidewayspos + 2000, 10000, -forwardpos + 2000, 0.0};
		GLfloat global_ambient[]={0.2, 0.2, 0.2, 1.0};

		GLfloat light_ambient1[]={0.1, 0.1, 0.1, 1.0};
		GLfloat light_diffuse1[]={1.0, 1.0, 1.0, 1.0};
		GLfloat light_specular1[]={1.0, 1.0, 1.0, 1.0};
		//GLfloat light_position1[]={-sidewayspos - 2000, 10000, forwardpos - 2000, 0.0};


		GLfloat light_ambient2[]={0.1, 0.1, 0.1, 1.0};
		GLfloat light_diffuse2[]={1.0, 1.0, 1.0, 1.0};
		GLfloat light_specular2[]={1.0, 1.0, 1.0, 1.0};
		GLfloat light_position2[]={-1.0f, 1.0f, 1.0f, 0.0f};


		GLfloat light_ambient3[]={0.1, 0.1, 0.1, 1.0};
		GLfloat light_diffuse3[]={1.0, 1.0, 1.0, 1.0};
		GLfloat light_specular3[]={1.0, 1.0, 1.0, 1.0};
		//GLfloat light_position3[]={-sidewayspos - 2000, 10000, forwardpos + 2000, 0.0};

		//sets the lighting variables into the glLight functions
		//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

		//glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

		glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
		glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient2);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);

		//glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
		glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient3);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse3);
		glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular3);

		//starts the defaults for the materials, will change once material functions are called
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

		//sets global ambient light
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

		//enables the shading and light modules as well as lighting
		glShadeModel(GL_SMOOTH);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		//glEnable(GL_LIGHT1);
		//lights 2 and 3 are taken out because world looks natural without them
		glEnable(GL_LIGHT2);
		//glEnable(GL_LIGHT3);

		//glDepthFunc(GL_LEQUAL);
		//enables depth test to hide what are behind objects.
		glEnable(GL_DEPTH_TEST);

		//sets background light blue color for the sky
		glClearColor(51.0/255.0,189.0/255.0,255.0/255.0,1.0);
		//clears the bufferbit and the depth buffer bit to draw the next step in animation
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//load a new identity
		glLoadIdentity();
		//sets the lookat function to the variables which allow control for changing
		gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz);

		elevation = elevation + updownspeed; // sets the elevation to change with the updownspeed

		// the following functions create the physics system

		// 1.  Stalling,  if the plane climbs at too great an angle, the wings will no longer achieve
		//     lift using Bernouli's Principle because the air travelling across the top of the wing is
		//	   disrupted.  This will result in a sudden loss of lift or a drop in the plane's pitch and
		//	   altitude until the wings again begin to create lift.
		if (theta[0] < -30){ // if the plane is climbing at a greater than 30 degree angle
			stalling = 1; // the plane stalls
		}

		if (theta[0] > 20){ // it then will stop stalling when it reaches a -30 degree angle
			stalling = 0;
		}

		if (stalling) stallanimate(); // if it is stalling, then call the stall function


		// 2.  Speed and lift.  If the plane is not travelling through the air fast enought, then the wings
		//	   will no longer be creating enough lift to balance out for the weight of the plane.  This will
		//	   create a gradual dropping of pitch and attitude dependant on how fast the plane is moving.
		//     The slower the movement then the quicker it will drop.  This will continue until the plane starts
		//     moving fast enough again to get enough lift.
		if (propvar < 60 && propvar != 0){ // if the plane is not moving fast enough
			updownspeed -= (30/propvar) * 0.1; // it will start losing altitude
			theta[0] += 2 * (30.0/propvar) * 0.1; // as well as lose pitch
			if (theta[0] > 90) theta[0] = 90; // if it is going straight down, it will continue to go straight down

		}

		// 3.  Through the ground.  An airplane cannot go through the ground.  This is a very simple collision
		//	   detection with the ground, basically if it tries to get a negative altitude then it simply stays
		//     at zero, the plane becomes level.
		if (elevation < 0){ // if the plane tries to go beneath the surface of the ground
			elevation = 0;// it will return to on the ground
			updownspeed = 0; // it will have no up/down speed
			theta[0] = 0;// it will have no pitch
		}

		// 4.  Take-off.  The plane cannot take off until a minimum speed is reached to create enough lift to bring it
		//     off the ground.  This keeps the plane to the ground until the necessary speed is reached.
		if (elevation < 10){ // if it tries to lift off the ground
			if (propvar < 60){ // if it is not going fast enough
				theta[0] = 0; // it will not have any pitch
				elevation = 0; // it will stay on the ground
				updownspeed = 0; // it will not have an up/down speed
			}
		}

		// 5.  No power.  if the plane is completely with out power then it is producing no lift what so ever and will drop
		//     very quickly.
		if (propvar == 0 && elevation != 0){ // if the propellor is not spinning and is not on the ground.
			elevation -= 30; // elevation drops significantly
			theta[0] += 3; // starts to lose pitch very quickly
			if (theta[0] > 90) theta[0] = 90; // will not have a pitch below straight down
		}

		if (insidecamera == 1){ // if inside the plane will rotate the entire ground and buildings to adjust for plane movement
		glRotatef(theta[0], -1.0, 0.0, 0.0); // call rotation functions
		glRotatef(planeyaw, 0.0, 1.0, 0.0);
		glRotatef(theta[2], 0.0, 0.0, -1.0);
		}

		glRotatef(theta[1], 0.0, 1.0, 0.0); // rotates the ground and buildings around the y axis

		glTranslatef(sidewayspos, -elevation, -forwardpos); // moves the ground and buildings underneath the plane

		drawgroundandbuildings(); // function to call drawing functions for the ground and the buildings

		glLoadIdentity(); // load new identity for different animation for the plane

		gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz); // set the camera settings again for new identity
		if (insidecamera == 0){ // if we are not inside the plane, the plane will be rotated for yaw (some) pitch and roll
    		glRotatef(theta[0], 1.0, 0.0, 0.0); // call rotation functions
    		glRotatef(planeyaw, 0.0, 1.0, 0.0);
    		glRotatef(theta[2], 0.0, 0.0, 1.0);
		}

		drawairplane(); // calls function to draw the airplane

	//#ifdef DEBUG
		gotoxy(1 ,3 );printf("theta[0] %.02f",theta[0]);
		gotoxy(21,3 );printf("theta[1] %.02f",theta[1]);
		gotoxy(41,3 );printf("theta[2] %.02f",theta[2]);


		gotoxy(1 ,4 );printf("yaw0 %.02f",yaw0);
		gotoxy(21,4 );printf("yaw1 %.02f",yaw1);
		gotoxy(41,4 );printf("planeyaw %.02f",planeyaw);
		gotoxy(61,4 );printf("turnspeed %.02f",turnspeed);

		gotoxy(1 ,5 );printf("propspin %.02f",propspin);
		gotoxy(21,5 );printf("propvar %.02f",propvar);
		gotoxy(1 ,6 );printf("elevation %.02f",elevation);
		gotoxy(21,6 );printf("updownspeed %.02f",updownspeed);
		gotoxy(1 ,7 );printf("speed %.02f",speed);gotoxy(1 ,21);
	//#endif

	}






	//if window is reshaped call this to keep aspect ratio
	//function taken from the book, glOrtho was change to fit my needs

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void myReshape(int w, int h)
	{
		glMatrixMode(GL_PROJECTION); // puts into projection mode
		glViewport(0, 0, w, h); // sets the viewport
		glLoadIdentity(); // loads identity
		gluPerspective(55.0, w/h, 1, 10000); // sets the perspective for a 55 degree angle width/height ratio starting at 1 going to 10000
		glMatrixMode(GL_MODELVIEW); // returns back to Modelview mode
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	//function to draw the ground and all the buildings, the root of the hierarchical drawing



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
		glTranslatef(0.0, -80.0, 1000); // moves building into place
		drawmiller();
		glTranslatef(2000.0, 0.0, 1200.0); // moves building into place
		drawmiller(); // miller called again for Whitcomb becasue of nearly identical design of buildings
		glTranslatef(5000.0, 0.0, 0.0); // moves building into place
		drawhenry();
		glPushMatrix();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	// hierarchical function call for drawing the airplane as well as rotation of the prop




	void drawairplane()
	{
		bluematerial(); // set color to blue
		drawbody();

		whitematerial(); // set color to white
		drawwings();
		drawtailwings();

		redmaterial(); // set color to red
		drawstruts();
		drawlandinggears();
		drawnosegear();
		drawnose();

		whitematerial(); // set color to white
		glTranslatef(0.0,-10.0,0.0); // moves prop to x axis
		glRotatef(propspin, 0.0,0.0,-1.0); // rotates prop along z axis
		glTranslatef(0.0,10.0,0.0); // moves prop back into position
		drawprop();
		glFlush();
		glutSwapBuffers();
		glPopMatrix();

	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	//		Code for the texture comes from the tutuorial by Nate Robins
	//		Was taken from the textures tutorial and modified slightly to fit my needs
	//		commented lines were commented by me, also the values of glTexParameters were edited by me
	//      Nate Robins, 1997, 2000
	//      nate@pobox.com, http://www.pobox.com/~nate

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	void
	wingtexenv(void)
	{
		GLfloat env_color[4], border_color[4];

		//cell_vector(env_color, ecolor, 4);
		//cell_vector(border_color, bcolor, 4);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, env_color);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	}
	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void
	wingtexture(void)
	{
		wingtexenv();
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, iwidth, iheight, GL_RGB, GL_UNSIGNED_BYTE, image);
	}

	//		End of Nate Robins code


	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	//		Code for the texture comes from the tutuorial by Nate Robins
	//		Was taken from the textures tutorial and modified slightly to fit my needs
	//		commented lines were commented by me, also the values of glTexParameters were edited by me
	//      Nate Robins, 1997, 2000
	//      nate@pobox.com, http://www.pobox.com/~nate

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void texenv(void)
	{
		GLfloat env_color[4], border_color[4];

		//cell_vector(env_color, ecolor, 4);
		//cell_vector(border_color, bcolor, 4);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, env_color);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************




	void texture(void)
	{
		texenv();
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, iwidth, iheight, GL_RGB, GL_UNSIGNED_BYTE, image);
	}

	//		End of Nate Robins code




}
