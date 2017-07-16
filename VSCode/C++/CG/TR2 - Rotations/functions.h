float objx = 0.0f;
float objy = 0.0f;
float anglearm = 0.0f;
float anglesidearm = 0.0f;
float scaling = 1.0f;

void initialize(void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1 ,1);
}

void draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(0.0, 0.0, 0.0);
	glScalef(scaling, scaling, 1.0);
	glTranslatef(0.0, 0.0, 0.0);

    glTranslatef(objx, objy, 0.0);
	body();
    head();

	glTranslatef(13*base/4, base*6, 0.0);
	glRotatef(anglearm, 0.0, 0.0, 1.0);
	glTranslatef(-13*base/4, -base*6, 0.0);
	arm();

    glTranslatef(13*base/4, base*3, 0.0);
	glRotatef(anglesidearm, 0.0, 0.0, 1.0);
	glTranslatef(-13*base/4, -base*3, 0.0);
	sidearm();

	glFlush();
}
