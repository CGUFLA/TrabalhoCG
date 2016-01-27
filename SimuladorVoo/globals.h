namespace nsCessna
{

	// array de caracteres para soletrar "Press Spacebar to Continue"
	char spacebar[26] = {'P','r','e','s','s',' ','S','p','a','c','e','b','a','r',' ','t','o',' ','C','o','n','t','i','n','u','e'};
	int j = 0;
	static GLfloat theta[] = {0.0,-90.0,0.0};//para rotação
	static GLfloat turnspeed = 0.0; // velocidade de rotação
	static GLfloat yaw0 = 0;//para dar uma guinada o mouse deve ser pressionado, ou os botões de controle
	static GLfloat yaw1 = 0;
	static GLfloat planeyaw = 0; // anglo da guinada

	static GLfloat propvar=0; // velocidade da helice
	static GLfloat elevation = 0; // altura do avião em relação ao chão
	static GLfloat updownspeed = 0; // velocidade a que a altura vai alterar
	static GLfloat speed = 0; // velocidade de movimento do plano
	float forwardpos = -350; // posição no eixo y em que o avião começa em relação ao chão
	float sidewayspos = 0; // posição no eixo X em que o avião começa em relação ao chão
	int stalling = 0;

	GLfloat splash[][2] = {{0,0},{0,300},{300,300},{300,0}};

	int mainwindow, splashscreen, rx, ry, i; // variaveis para o dimensionamento e redimensionamento da janela
	float eyex, eyey, eyez, atx, aty, atz, upx, upy, upz; // variaveis para a camera com a função glLookAt
	int floatcamera = 0;
	int insidecamera = 0;
	int bowlerpoles;
	int bowlersteps;

	GLint offset = 0;  // contador para o posicionamento de pilares das casas
	static GLfloat propspin = 0; // angulo de propulsão da helice
	unsigned char* image = NULL;
	int iheight, iwidth;



	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	}

}
