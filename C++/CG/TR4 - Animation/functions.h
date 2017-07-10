int pos_x = 0;
int passo_x = 5;
int pos_y = 0;
int passo_y = 6;

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(pos_x, pos_y, 0.0);
    glTranslatef(100, 150, 0.0);
    glTranslatef(-100, -150, 0.0);

	Desenha_Quadrado();
	glutSwapBuffers();
}

void Anima(int value)
{
	pos_x += passo_x;
	pos_y += passo_y;

	if(pos_x > 350 || pos_x < -50)
		passo_x = (-1)*passo_x;
	if(pos_y > 300 || pos_y < -100)
		passo_y = (-1)*passo_y;

	glutPostRedisplay();
	glutTimerFunc(50.0/3.0, Anima, 1);
}

void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, LARGURA, 0, ALTURA);
}
