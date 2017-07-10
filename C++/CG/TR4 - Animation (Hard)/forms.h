//Desenha origem:
void Desenha_Origem()
{
	glColor3f(0.0, 0.0, 1.0);

	glPointSize(4);

	glBegin(GL_POINTS);
		glVertex3i(0, 0, 0);
	glEnd();
}

//Desenhar o piso:
void Desenha_Piso()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(0.7, 0.9, 0.7);

    glBegin(GL_QUADS);
        glVertex3i(-4, -4, 0);
        glVertex3i(-4, 4, 0);
        glVertex3i(4, 4, 0);
        glVertex3i(4, -4, 0);
    glEnd();

    glColor3f(0.0, 0.0, 0.9);

    glBegin(GL_LINES);
        glVertex3i(-4, -4, 0);
        glVertex3i(-4, 4, 0);

        glVertex3i(-3, -4, 0);
        glVertex3i(-3, 4, 0);

        glVertex3i(-2, -4, 0);
        glVertex3i(-2, 4, 0);    
        
        glVertex3i(-1, -4, 0);
        glVertex3i(-1, 4, 0);    
        
        glVertex3i(0, -4, 0);
        glVertex3i(0, 4, 0);    
        
        glVertex3i(1, -4, 0);
        glVertex3i(1, 4, 0);
        
        glVertex3i(2, -4, 0);
        glVertex3i(2, 4, 0);

        glVertex3i(3, -4, 0);
        glVertex3i(3, 4, 0);

        glVertex3i(4, -4, 0);
        glVertex3i(4, 4, 0);

        glVertex3i(-4, -4, 0);
        glVertex3i(4, -4, 0);

        glVertex3i(-4, -3, 0);
        glVertex3i(4, -3, 0);

        glVertex3i(-4, -2, 0);
        glVertex3i(4, -2, 0);

        glVertex3i(-4, -1, 0);
        glVertex3i(4, -1, 0);

        glVertex3i(-4, 0, 0);
        glVertex3i(4, 0, 0);

        glVertex3i(-4, 1, 0);
        glVertex3i(4, 1, 0);

        glVertex3i(-4, 2, 0);
        glVertex3i(4, 2, 0);

        glVertex3i(-4, 3, 0);
        glVertex3i(4, 3, 0);

        glVertex3i(-4, 4, 0);
        glVertex3i(4, 4, 0);
    glEnd();
}

//desenhar o quadrado:

void Desenha_Cubo()
{
    glColor3f(0.0, 0.0, 0.0);
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_QUADS);
        //Face de baixo:
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        //Face de cima:
        glVertex3f(-0.5, -0.5, 1.5);
        glVertex3f(-0.5, 0.5, 1.5);
        glVertex3f(0.5, 0.5, 1.5);
        glVertex3f(0.5, -0.5, 1.5);
        //Face de frente:
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 1.5);
        glVertex3f(0.5, 0.5, 1.5);
        glVertex3f(0.5, 0.5, 0.5);
        //Face de trás:
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 1.5);
        glVertex3f(0.5, -0.5, 1.5);
        glVertex3f(0.5, -0.5, 0.5);
        //Face de esquerda:
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 1.5);
        glVertex3f(-0.5, -0.5, 1.5);
        //Face de direita:
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, 1.5);
        glVertex3f(0.5, -0.5, 1.5);
    glEnd();
}

void Desenha_Inimigo_A()
{
    glColor3f(1.0f, 0.8f, 0.8f);

    glBegin(GL_QUADS);
        glVertex3f(3.0, 3.0, 1.0);
        glVertex3f(3.0, 3.0, 1.5);
        glVertex3f(2.5, 3.0, 1.5);
        glVertex3f(2.5, 3.0, 1.0);
    glEnd();

    glPointSize(4);
    
    glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
		glVertex3f(2.6, 3.0, 1.4);
		glVertex3f(2.9, 3.0, 1.4);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(3.0, 3.0, 1.5);
		glVertex3f(2.8, 3.0, 1.4);
        
		glVertex3f(2.5, 3.0, 1.5);
		glVertex3f(2.7, 3.0, 1.4);
	glEnd();
}

void Desenha_Inimigo_B()
{
    glColor3f(0.8f, 0.8f, 1.0f);

    glBegin(GL_QUADS);
        glVertex3f(-3.0, -3.0, 1.0);
        glVertex3f(-3.0, -3.0, 1.5);
        glVertex3f(-2.5, -3.0, 1.5);
        glVertex3f(-2.5, -3.0, 1.0);
    glEnd();

    glPointSize(4);
    
    glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
		glVertex3f(-2.6, -3.0, 1.4);
		glVertex3f(-2.9, -3.0, 1.4);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-3.0, -3.0, 1.5);
		glVertex3f(-2.8, -3.0, 1.4);
        
		glVertex3f(-2.5, -3.0, 1.5);
		glVertex3f(-2.7, -3.0, 1.4);
	glEnd();
}
