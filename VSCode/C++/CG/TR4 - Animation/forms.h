void Desenha_Quadrado()
{
	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
		glVertex2i(50, 100);
		glVertex2i(50, 200);
		glVertex2i(150, 200);
		glVertex2i(150, 100);
	glEnd();
}