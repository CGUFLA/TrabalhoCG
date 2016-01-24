
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



//material default values set so that they replace the color created with commented line that appears before it by a material.
//Key to material variable names:  [color]mat_[type]

	//	glColor3f(0.6,0.1,0.1); the color of the bricks
		GLfloat redmat_specular[]={0.6, 0.1, 0.1, 1.0};
        GLfloat redmat_diffuse[]={0.1, 0.1, 0.1, 1.0};
        GLfloat redmat_ambient[]={0.2, 0.3, 0.4, 1.0};
        GLfloat redmat_shininess={0.0};

	//glColor3f(0.25,0.25,0.25); whitish color for plane features

		GLfloat whitemat_specular[]={0.5, 0.5, 0.5, 1.0};
        GLfloat whitemat_diffuse[]={0.85, 0.85, 0.85, 1.0};
        GLfloat whitemat_ambient[]={0.5, 0.5, 0.5, 1.0};
        GLfloat whitemat_shininess={32.0};

	//	glColor3f(0.8,0.8,0.8); the color of the grey used for cement stairs

		GLfloat tanmat_specular[]={0.1, 0.1, 0.1, 1.0};
        GLfloat tanmat_diffuse[]={0.85, 0.85, 0.8, 1.0};
        GLfloat tanmat_ambient[]={0.65, 0.65, 0.6, 1.0};
        GLfloat tanmat_shininess={2.0};

	//	glColor3f(0.0,0.5,1.0); blue for plane features

		GLfloat bluemat_specular[]={0.0, 0.25, 0.5, 1.0};
        GLfloat bluemat_diffuse[]={0.0, 0.5, 1.0, 1.0};
        GLfloat bluemat_ambient[]={0.6, 0.6, 0.6, 1.0};
        GLfloat bluemat_shininess={32.0};

	// ground color
		GLfloat grassmat_specular[]={0.2, 0.2, 0.2, 1.0};
        GLfloat grassmat_diffuse[]={0.2, 1.0, 0.2, 1.0};
        GLfloat grassmat_ambient[]={0.1, 0.8, 0.1, 1.0};
        GLfloat grassmat_shininess={0.0};

	// color for the roofs of buildings very dark
		GLfloat roofmat_specular[]={0.2, 0.2, 0.2, 1.0};
        GLfloat roofmat_diffuse[]={0.2, 0.2, 0.2, 1.0};
        GLfloat roofmat_ambient[]={0.2, 0.2, 0.2, 1.0};
        GLfloat roofmat_shininess={100.0};


	// color for Hinsdale bricks
		GLfloat yellowmat_specular[]={215.0/256.0, 172.0/256.0, 0.0, 1.0};
        GLfloat yellowmat_diffuse[]={215.0/256.0, 172.0/256.0, 0.0, 1.0};
        GLfloat yellowmat_ambient[]={0.2, 0.2, 0.2, 1.0};
        GLfloat yellowmat_shininess={100.0};


// **********************************************************************
// *                                                                    *
// **********************************************************************

	// The following are the various functions to easily change between colors while rendering.
	// Key to function names:  [color]material()
// **********************************************************************
// *                                                                    *
// **********************************************************************



// **********************************************************************
// *                                                                    *
// **********************************************************************


		void yellowmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, yellowmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, yellowmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yellowmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, yellowmat_shininess);
		}

// **********************************************************************
// *                                                                    *
// **********************************************************************

		void redmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, redmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, redmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, redmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, redmat_shininess);
		}
// **********************************************************************
// *                                                                    *
// **********************************************************************
		void whitematerial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whitemat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, whitemat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, whitemat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, whitemat_shininess);
		}
// **********************************************************************
// *                                                                    *
// **********************************************************************
		void tanmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tanmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tanmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tanmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tanmat_shininess);
		}
// **********************************************************************
// *                                                                    *
// **********************************************************************
		void bluematerial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, bluemat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, bluemat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, bluemat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, bluemat_shininess);
		}

// **********************************************************************
// *                                                                    *
// **********************************************************************

		void grassmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grassmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grassmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grassmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, grassmat_shininess);
		}

// **********************************************************************
// *                                                                    *
// **********************************************************************


		void roofmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, roofmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, roofmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, roofmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, roofmat_shininess);
		}



}
