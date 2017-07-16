void kbmanagement(unsigned char key, int x, int y)
{
    switch (key)
    {
		case 's':
            scaling+=0.1f;
        break;

		case 'S':
            scaling-=0.1f;
        break;

		case 'r':
            anglearm+=6.0f;
        break;

		case 'e':
            anglesidearm+=6.0f;
        break;
    }
    glutPostRedisplay();
}

void arrows(int key, int x, int y)
{
    switch (key)
    {
		case GLUT_KEY_UP:
            objy+=1.0f;
        break;

		case GLUT_KEY_DOWN:
            objy-=1.0f;
        break;

		case GLUT_KEY_LEFT:
            objx-=1.0f;
        break;

		case GLUT_KEY_RIGHT:
            objx+=1.0f;
        break;
    }
    glutPostRedisplay();
}

