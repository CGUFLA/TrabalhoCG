


namespace nsCessna
{

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void showtext() // function for showing the splash screen while program is loading
	{
		glLoadIdentity(); // load a new identity
		glClearColor(51.0/255.0,189.0/255.0,255.0/255.0,1.0); // load blud background color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears the buffer bits

		glColor3f(0.0,0.0,1.0); // sets the color for writing the texts
		glLoadIdentity(); // loads new identity

		//sets raster coordinates for where text is to be written
		rx = -200;
		ry = -290;

		for (i = 0; i < 26; i++){ // steps through displaying all the characters
			glRasterPos2i(rx,ry); // loads the position
			glColor3f(0.0,0.0 + j/40.0,1.0-j/40.0); // sets the color, changes from blue to green for nice effect
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, spacebar[i]); // displays the character
			rx+=glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, spacebar[i])*1.5; // moves the raster position into next place
			j++; // increments the character
		}

		glFlush();

		// Original idea here was to have a smaller window come up while the rest of the program is loading.  The window
		// would contain a small intoductory type image with instructions on how to use the program.  Also the text
		// Press Spacebar to Continue would be placed beneath to close the window and start the rest of the program.
		// The original bitmap was too large to be directly changed into a ppm and used.  When a smaller bitmap was then
		// used and then blown up into the size that I originally wanted it, the picture looked all distorted and the text
		// became almost un-readable.  To fix this, the image was split into four different images which were then texture
		// mapped onto four different polygons which were then placed in the appropriate order and sized correctly.  The
		// result was very acceptable and can hardly tell that there are four images instead of just one.

		//image = glmReadPPM("splash1-4.ppm", &iwidth, &iheight); // loads first image for splash screen

		texture(); // calls texture function

		//draws first polygon with first image texture mapped
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glTranslatef(300,1,0);
		glRotatef(180, 0, 0, 1);
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex2fv(splash[0]);
		glTexCoord2f(1, 1);
		glVertex2fv(splash[1]);
		glTexCoord2f(0, 1);
		glVertex2fv(splash[2]);
		glTexCoord2f(0, 0);
		glVertex2fv(splash[3]);
		glEnd();

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);

		//image = glmReadPPM("splash1-3.ppm", &iwidth, &iheight); //loads second image

		texture(); // calls texture function

		//draws second polygon with first second texture mapped
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glRotatef(180, 0, 0, 1);
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex2fv(splash[0]);
		glTexCoord2f(1, 1);
		glVertex2fv(splash[1]);
		glTexCoord2f(0, 1);
		glVertex2fv(splash[2]);
		glTexCoord2f(0, 0);
		glVertex2fv(splash[3]);
		glEnd();

		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

		//image = glmReadPPM("splash1-2.ppm", &iwidth, &iheight); // loads third image

		texture(); // calls texture function

		//draws third polygon with first third texture mapped
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glTranslatef(299,300,0);
		glRotatef(180, 0, 0, 1);

		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex2fv(splash[0]);
		glTexCoord2f(1, 1);
		glVertex2fv(splash[1]);
		glTexCoord2f(1.0/300.0, 1);
		glVertex2fv(splash[2]);
		glTexCoord2f(1.0/300.0, 0);
		glVertex2fv(splash[3]);
		glEnd();

		glPopMatrix();

		glDisable(GL_TEXTURE_2D);

		//image = glmReadPPM("splash1-1.ppm", &iwidth, &iheight); // loads fourth image

		texture(); // calls texture function

		//draws fourth polygon with first fourth texture mapped
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glTranslatef(0,301,0);
		glRotatef(180, 0, 0, 1);
		glScalef(301.0/300.0, 301.0/300.0, 0);
		glBegin(GL_POLYGON);
		glTexCoord2f(1, 0);
		glVertex2fv(splash[0]);
		glTexCoord2f(1, 1);
		glVertex2fv(splash[1]);
		glTexCoord2f(0, 1);
		glVertex2fv(splash[2]);
		glTexCoord2f(0, 0);
		glVertex2fv(splash[3]);
		glEnd();

		glPopMatrix();
		glDisable(GL_TEXTURE_2D);

		glFlush();
		glutSwapBuffers();


	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	// The following is the display function for the splash screen window




	void splashdisplay(void)
	{
		glMatrixMode(GL_PROJECTION); // puts into projection mode
		glLoadIdentity(); // load new identity
		glOrtho(-300.0, 300.0, -300.0, 300.0, -1.0, 1.0); // sets orthological projection settings
		glMatrixMode(GL_MODELVIEW); // back into modelview mode

		showtext(); // calls the function to show text and image
	}


}

