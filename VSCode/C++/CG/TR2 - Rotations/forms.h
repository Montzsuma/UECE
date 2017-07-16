void body()
{
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2i(0, 0);
        glVertex2i(0, base*6);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex2i(base*3, base*6);
        glVertex2i(base*3, 0);
    glEnd();
}

void head()
{
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2i(base/2, base*6);
        glVertex2i(base/2, base*8);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex2i((base*5)/2, base*8);
        glVertex2i((base*5)/2, base*6);
    glEnd();
}

void arm()
{
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(base*3, base*3);
        glVertex2i(base*3, base*6);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex2i((base*7)/2, base*6);
        glVertex2i((base*7)/2, base*3);
    glEnd();
}

void sidearm()
{
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(base*3, base);
        glVertex2i(base*3, base*3);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex2i((base*7)/2, base*3);
        glVertex2i((base*7)/2, base);
    glEnd();
}

