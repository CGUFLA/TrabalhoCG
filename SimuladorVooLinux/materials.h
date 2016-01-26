namespace nsCessna
{



//cores padrão de um material

	//	glColor3f(0.6,0.1,0.1); cor dos tijolos
		GLfloat redmat_specular[]={0.6, 0.1, 0.1, 1.0};
        GLfloat redmat_diffuse[]={0.1, 0.1, 0.1, 1.0};
        GLfloat redmat_ambient[]={0.2, 0.3, 0.4, 1.0};
        GLfloat redmat_shininess={0.0};

	//glColor3f(0.25,0.25,0.25); cor esbranquiçada de recursos do plano

		GLfloat whitemat_specular[]={0.5, 0.5, 0.5, 1.0};
        GLfloat whitemat_diffuse[]={0.85, 0.85, 0.85, 1.0};
        GLfloat whitemat_ambient[]={0.5, 0.5, 0.5, 1.0};
        GLfloat whitemat_shininess={32.0};

	//	glColor3f(0.8,0.8,0.8); cor cinzenta do cimento das escadas

		GLfloat tanmat_specular[]={0.1, 0.1, 0.1, 1.0};
        GLfloat tanmat_diffuse[]={0.85, 0.85, 0.8, 1.0};
        GLfloat tanmat_ambient[]={0.65, 0.65, 0.6, 1.0};
        GLfloat tanmat_shininess={2.0};

	//	glColor3f(0.0,0.5,1.0); azul para detalhes do avião

		GLfloat bluemat_specular[]={0.0, 0.25, 0.5, 1.0};
        GLfloat bluemat_diffuse[]={0.0, 0.5, 1.0, 1.0};
        GLfloat bluemat_ambient[]={0.6, 0.6, 0.6, 1.0};
        GLfloat bluemat_shininess={32.0};

	// cor de fundo
		GLfloat grassmat_specular[]={0.2, 0.2, 0.2, 1.0};
        GLfloat grassmat_diffuse[]={0.2, 1.0, 0.2, 1.0};
        GLfloat grassmat_ambient[]={0.1, 0.8, 0.1, 1.0};
        GLfloat grassmat_shininess={0.0};

	// cor mais escura para os telhados dos edificios
		GLfloat roofmat_specular[]={0.2, 0.2, 0.2, 1.0};
        GLfloat roofmat_diffuse[]={0.2, 0.2, 0.2, 1.0};
        GLfloat roofmat_ambient[]={0.2, 0.2, 0.2, 1.0};
        GLfloat roofmat_shininess={100.0};


	// Cor de tijolos
		GLfloat yellowmat_specular[]={215.0/256.0, 172.0/256.0, 0.0, 1.0};
        GLfloat yellowmat_diffuse[]={215.0/256.0, 172.0/256.0, 0.0, 1.0};
        GLfloat yellowmat_ambient[]={0.2, 0.2, 0.2, 1.0};
        GLfloat yellowmat_shininess={100.0};


// **********************************************************************
// *                                                                    *
// **********************************************************************

	// Funções para mudar cores durante a renderização
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


		void redmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, redmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, redmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, redmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, redmat_shininess);
		}

		void whitematerial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whitemat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, whitemat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, whitemat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, whitemat_shininess);
		}

		void tanmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tanmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tanmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tanmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tanmat_shininess);
		}

		void bluematerial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, bluemat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, bluemat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, bluemat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, bluemat_shininess);
		}


		void grassmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, grassmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, grassmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, grassmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, grassmat_shininess);
		}


		void roofmaterial(){
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, roofmat_specular);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, roofmat_ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, roofmat_diffuse);
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, roofmat_shininess);
		}



}
