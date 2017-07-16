#include "headers.h"
#include "forms.h"
#include "functions.h"
#include "commands.h"

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (WIDTH, HEIGHT);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Exercicio 2");
	glutDisplayFunc(draw);
	glutSpecialFunc(arrows);
	glutKeyboardFunc(kbmanagement);
	initialize();
	glutMainLoop();
	return 0;
}
