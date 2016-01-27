namespace nsCessna
{
	int j = 0;
	static GLfloat theta[] = {0.0,-90.0,0.0};//para rota��o
	static GLfloat turnspeed = 0.0; // velocidade de rota��o
	static GLfloat yaw0 = 0;//para dar uma guinada o mouse deve ser pressionado, ou os bot�es de controle
	static GLfloat yaw1 = 0;
	static GLfloat planeyaw = 0; // anglo da guinada

	static GLfloat propvar=0; // velocidade da helice
	static GLfloat elevation = 0; // altura do avi�o em rela��o ao ch�o
	static GLfloat updownspeed = 0; // velocidade a que a altura vai alterar
	static GLfloat speed = 0; // velocidade de movimento do plano
	float forwardpos = -350; // posi��o no eixo y em que o avi�o come�a em rela��o ao ch�o
	float sidewayspos = 0; // posi��o no eixo X em que o avi�o come�a em rela��o ao ch�o
	int stalling = 0;

	int mainwindow, splashscreen, rx, ry, i; // variaveis para o dimensionamento e redimensionamento da janela
	float eyex, eyey, eyez, atx, aty, atz, upx, upy, upz; // variaveis para a camera com a fun��o glLookAt
	int floatcamera = 0;
	int insidecamera = 0;
	int bowlerpoles;
	int bowlersteps;

	GLint offset = 0;  // contador para o posicionamento de pilares das casas
	static GLfloat propspin = 0; // angulo de propuls�o da helice
	unsigned char* image = NULL;
	int iheight, iwidth;

    // variaveis para o controle das cores da iluminacao
    float color_ambient;
    int pos;
    float red, blue, green;

    //funcao que imprime os valores do aviao no terminal
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	}

}
