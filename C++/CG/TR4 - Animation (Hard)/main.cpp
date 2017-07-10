#include "headers.h"

int main(int argc, char **argv)
{
	resetKeys();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Animacao Cubo 3D");
	glutDisplayFunc(Desenha);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	Inicializa();
	CriarMenu();
	glutTimerFunc(0, Anima, 0);
	glutMainLoop();
	return 0;
}