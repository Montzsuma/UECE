#include "headers.h"

int main(int argc, char **argv)
{
	initialize_world();
	resetKeys();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("DAMAS");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseFunc(Mouse_Press);
	Inicializa();
	CriarMenu();
	glutTimerFunc(0, Anima, 0);
	glutMainLoop();
	return 0;
}
