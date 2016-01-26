namespace nsCessna
{


//funções que desenham os polígonos que formam as cenas

// **********************************************************************
// *                                                                    *
// **********************************************************************


	void nosepolygon4(int a, int b, int c , int d)
	{
 		glBegin(GL_POLYGON);
			glNormal3fv(normalnose[a]);
			glVertex3fv(nose[a]);
			glNormal3fv(normalnose[b]);
			glVertex3fv(nose[b]);
			glNormal3fv(normalnose[c]);
			glVertex3fv(nose[c]);
			glNormal3fv(normalnose[d]);
			glVertex3fv(nose[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	void nosepolygon3(int a, int b, int c)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalnose[a]);
			glVertex3fv(nose[a]);
			glNormal3fv(normalnose[b]);
			glVertex3fv(nose[b]);
			glNormal3fv(normalnose[c]);
			glVertex3fv(nose[c]);
		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void proppolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalprop[a]);
			glVertex3fv(prop[a]);
			glNormal3fv(normalprop[b]);
			glVertex3fv(prop[b]);
			glNormal3fv(normalprop[c]);
			glVertex3fv(prop[c]);
			glNormal3fv(normalprop[d]);
			glVertex3fv(prop[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void lbodypolygon5(int a, int b, int c , int d, int e)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalbodyleft[a]);
			glVertex3fv(bodyleft[a]);
			glNormal3fv(normalbodyleft[b]);
			glVertex3fv(bodyleft[b]);
			glNormal3fv(normalbodyleft[c]);
			glVertex3fv(bodyleft[c]);
			glNormal3fv(normalbodyleft[d]);
			glVertex3fv(bodyleft[d]);
			glNormal3fv(normalbodyleft[e]);
			glVertex3fv(bodyleft[e]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void lbodypolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalbodyleft[a]);
			glVertex3fv(bodyleft[a]);
			glNormal3fv(normalbodyleft[b]);
			glVertex3fv(bodyleft[b]);
			glNormal3fv(normalbodyleft[c]);
			glVertex3fv(bodyleft[c]);
			glNormal3fv(normalbodyleft[d]);
			glVertex3fv(bodyleft[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void lbodypolygon3(int a, int b, int c)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalbodyleft[a]);
			glVertex3fv(bodyleft[a]);
			glNormal3fv(normalbodyleft[b]);
			glVertex3fv(bodyleft[b]);
			glNormal3fv(normalbodyleft[c]);
			glVertex3fv(bodyleft[c]);
		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void rbodypolygon5(int a, int b, int c , int d, int e)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalbodyright[a]);
			glVertex3fv(bodyright[a]);
			glNormal3fv(normalbodyright[b]);
			glVertex3fv(bodyright[b]);
			glNormal3fv(normalbodyright[c]);
			glVertex3fv(bodyright[c]);
			glNormal3fv(normalbodyright[d]);
			glVertex3fv(bodyright[d]);
			glNormal3fv(normalbodyright[e]);
			glVertex3fv(bodyright[e]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void rbodypolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalbodyright[a]);
			glVertex3fv(bodyright[a]);
			glNormal3fv(normalbodyright[b]);
			glVertex3fv(bodyright[b]);
			glNormal3fv(normalbodyright[c]);
			glVertex3fv(bodyright[c]);
			glNormal3fv(normalbodyright[d]);
			glVertex3fv(bodyright[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void rbodypolygon3(int a, int b, int c)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalbodyright[a]);
			glVertex3fv(bodyright[a]);
			glNormal3fv(normalbodyright[b]);
			glVertex3fv(bodyright[b]);
			glNormal3fv(normalbodyright[c]);
			glVertex3fv(bodyright[c]);
		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void rlbodypolygon4(int a, int b)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalbodyright[a]);
			glVertex3fv(bodyright[a]);
			glNormal3fv(normalbodyleft[a]);
			glVertex3fv(bodyleft[a]);
			glNormal3fv(normalbodyleft[b]);
			glVertex3fv(bodyleft[b]);
			glNormal3fv(normalbodyright[b]);
			glVertex3fv(bodyright[b]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void llandingpolygon6(int a, int b, int c , int d, int e, int f)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalleftlandinggear[a]);
			glVertex3fv(leftlandinggear[a]);
			glNormal3fv(normalleftlandinggear[b]);
			glVertex3fv(leftlandinggear[b]);
			glNormal3fv(normalleftlandinggear[c]);
			glVertex3fv(leftlandinggear[c]);
			glNormal3fv(normalleftlandinggear[d]);
			glVertex3fv(leftlandinggear[d]);
			glNormal3fv(normalleftlandinggear[e]);
			glVertex3fv(leftlandinggear[e]);
			glNormal3fv(normalleftlandinggear[f]);
			glVertex3fv(leftlandinggear[f]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void llandingpolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalleftlandinggear[a]);
			glVertex3fv(leftlandinggear[a]);
			glNormal3fv(normalleftlandinggear[b]);
			glVertex3fv(leftlandinggear[b]);
			glNormal3fv(normalleftlandinggear[c]);
			glVertex3fv(leftlandinggear[c]);
			glNormal3fv(normalleftlandinggear[d]);
			glVertex3fv(leftlandinggear[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void rlandingpolygon6(int a, int b, int c , int d, int e, int f)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalrightlandinggear[a]);
			glVertex3fv(rightlandinggear[a]);
			glNormal3fv(normalrightlandinggear[b]);
			glVertex3fv(rightlandinggear[b]);
			glNormal3fv(normalrightlandinggear[c]);
			glVertex3fv(rightlandinggear[c]);
			glNormal3fv(normalrightlandinggear[d]);
			glVertex3fv(rightlandinggear[d]);
			glNormal3fv(normalrightlandinggear[e]);
			glVertex3fv(rightlandinggear[e]);
			glNormal3fv(normalrightlandinggear[f]);
			glVertex3fv(rightlandinggear[f]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void rlandingpolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalrightlandinggear[a]);
			glVertex3fv(rightlandinggear[a]);
			glNormal3fv(normalrightlandinggear[b]);
			glVertex3fv(rightlandinggear[b]);
			glNormal3fv(normalrightlandinggear[c]);
			glVertex3fv(rightlandinggear[c]);
			glNormal3fv(normalrightlandinggear[d]);
			glVertex3fv(rightlandinggear[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void nosegearpolygon6(int a, int b, int c , int d, int e, int f)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalnosegear[a]);
			glVertex3fv(nosegear[a]);
			glNormal3fv(normalnosegear[b]);
			glVertex3fv(nosegear[b]);
			glNormal3fv(normalnosegear[c]);
			glVertex3fv(nosegear[c]);
			glNormal3fv(normalnosegear[d]);
			glVertex3fv(nosegear[d]);
			glNormal3fv(normalnosegear[e]);
			glVertex3fv(nosegear[e]);
			glNormal3fv(normalnosegear[f]);
			glVertex3fv(nosegear[f]);

		glEnd();
	}
	// **********************************************************************
	// *                                                                    *
	// **********************************************************************


	void nosegearpolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalnosegear[a]);
			glVertex3fv(nosegear[a]);
			glNormal3fv(normalnosegear[b]);
			glVertex3fv(nosegear[b]);
			glNormal3fv(normalnosegear[c]);
			glVertex3fv(nosegear[c]);
			glNormal3fv(normalnosegear[d]);
			glVertex3fv(nosegear[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************




	void strutspolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalstruts[a]);
			glVertex3fv(struts[a]);
			glNormal3fv(normalstruts[b]);
			glVertex3fv(struts[b]);
			glNormal3fv(normalstruts[c]);
			glVertex3fv(struts[c]);
			glNormal3fv(normalstruts[d]);
			glVertex3fv(struts[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************



	void millerpolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalmiller[a]);
			glVertex3fv(miller[a]);
			glNormal3fv(normalmiller[b]);
			glVertex3fv(miller[b]);
			glNormal3fv(normalmiller[c]);
			glVertex3fv(miller[c]);
			glNormal3fv(normalmiller[d]);
			glVertex3fv(miller[d]);

		glEnd();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************




	void henrypolygon4(int a, int b, int c , int d)
	{

 		glBegin(GL_POLYGON);
			glNormal3fv(normalhenry[a]);
			glVertex3fv(henry[a]);
			glNormal3fv(normalhenry[b]);
			glVertex3fv(henry[b]);
			glNormal3fv(normalhenry[c]);
			glVertex3fv(henry[c]);
			glNormal3fv(normalhenry[d]);
			glVertex3fv(henry[d]);

		glEnd();
	}
}
