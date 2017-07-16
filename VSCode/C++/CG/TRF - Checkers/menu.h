//Comandos do menu:
void Janela(int opcao)
{
	switch(opcao)
	{
		case 0:
			if(is_board_rotated)
				is_board_rotated = false;
			else
				is_board_rotated = true;
		break;
		case 1:
			initialize_world();
		break;
	}
	glutPostRedisplay();
}

void CriarMenu()
{
	glutCreateMenu(Janela);
	glutAddMenuEntry("Mudar visao", 0);
	glutAddMenuEntry("Reiniciar", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
