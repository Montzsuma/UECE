/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	//Câmera fixa
	if(!olhar && !seguir)
		gluLookAt(eyex,		eyey,	eyez,
				  lookx,	looky,	lookz,
				  upx,		upy,	upz);
	
	//Câmera olhando o cubo:
	if(olhar)
		gluLookAt(eyex, 		eyey, 			 eyez,
				  translate_x, 	translate_y,	 lookz,
				  upx,			upy,			 upz);

	//Câmera seguindo o cubo:
	if(seguir)
		gluLookAt(translate_x, translate_y-10.0,  eyez,
				  translate_x, 	translate_y,	 lookz,
				  upx,			upy,			 upz);
	
	Desenha_Piso();
	Desenha_Origem();

	//Movimentar o inimigo A:
	if(enemy)
	{
		glTranslatef(enemy_a_translate_x, enemy_a_translate_y, 0.0);
		Desenha_Inimigo_A();
		glTranslatef(-enemy_a_translate_x, -enemy_a_translate_y, 0.0);
		
		//Movimentar o inimigo B:
		glTranslatef(enemy_b_translate_x, enemy_b_translate_y, 0.0);
		Desenha_Inimigo_B();
		glTranslatef(-enemy_b_translate_x, -enemy_b_translate_y, 0.0);
	}
	//Movimentar o cubo:
	glTranslatef(translate_x, translate_y, translate_z);
	glRotatef(rotate_cube_x, 0.0, 1.0, 0.0);
	glRotatef(rotate_cube_y, 1.0, 0.0, 0.0);
    
	Desenha_Cubo();

	glutSwapBuffers();
}

void Anima(int value)
{
	//Move o cubo em movimento pendular:
	grau = grau + 0.1;
	if(grau==360.0)
		grau = 0.0;
	if(pendulo)
	{
		translate_z = sin(grau)/4.0;
	}
	else
		translate_z = 0.0;

	//Desfaz a rotação do cubo:
	if(rotate_cube_x !=0.0)
		if(rotate_cube_x > 0.0)
			rotate_cube_x-=0.5;
		else if(rotate_cube_x < 0.0)
			rotate_cube_x+=0.5;
	if(rotate_cube_y !=0.0)
		if(rotate_cube_y > 0.0)
			rotate_cube_y-=0.5;
		else if(rotate_cube_y < 0.0)
			rotate_cube_y+=0.5;

	//Move e rotaciona o cubo:
	if(keyStates['w'])
	{
		translate_y+=0.05f;
		if(rotate_cube_y >= -10.0)
			rotate_cube_y-=1.0f;
	}
	if(keyStates['s'])
	{
		translate_y-=0.05f;
		if(rotate_cube_y <= 10.0)
			rotate_cube_y+=1.0f;
	}
	if(keyStates['d'])
	{
		translate_x+=0.05f;
		if(rotate_cube_x <= 10.0)
			rotate_cube_x+=1.0f;
	}
	if(keyStates['a'])
	{
		translate_x-=0.05f;
		if(rotate_cube_x >= -10.0)
			rotate_cube_x-=1.0f;
	}

	//Move o inimigo:
	enemy_a_translate_x = sin(grau);
	enemy_a_translate_y = cos(grau);
	enemy_b_translate_x = -sin(grau);
	enemy_b_translate_y = -cos(grau);

	glutPostRedisplay();
	//Glorious 60 FPS
	glutTimerFunc(1000.0/60.0, Anima, ++value);
}

void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);
}
