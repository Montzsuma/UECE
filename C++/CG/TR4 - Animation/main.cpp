#include "headers.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Animacao Quadrado 2D");
	glutDisplayFunc(Desenha);
	Inicializa();
	glutTimerFunc(100, Anima, 1);
	glutMainLoop();
}