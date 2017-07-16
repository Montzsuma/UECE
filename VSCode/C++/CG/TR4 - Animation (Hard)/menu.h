//Comandos do menu:
void Janela(int opcao)
{
	switch(opcao){
		case 0:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);
			
			olhar = false;
			seguir = false;

			break;

		case 1:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-10, 10, -10, 10, -50 ,50);

			olhar = false;
			seguir = false;

		break;

		case 2:
			if(pendulo == true)
                pendulo = false;
            else
                pendulo = true;
		break;

		case 3:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);
			
            olhar = true;
			seguir = false;

		break;

		case 4:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);
			
			olhar = false;
			seguir = true;

		break;

		case 5:
			if(enemy == false)
				enemy = true;
			else
				enemy = false;
		break;
	}
	glutPostRedisplay();
}

void CriarMenu()
{
	glutCreateMenu(Janela);
	glutAddMenuEntry("Perspectiva", 0);
	glutAddMenuEntry("Ortogonal", 1);
	glutAddMenuEntry("Pendulo", 2);
	glutAddMenuEntry("Olhar", 3);
	glutAddMenuEntry("Seguir", 4);
	glutAddMenuEntry("Inimigos", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
