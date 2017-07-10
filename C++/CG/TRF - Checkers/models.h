//Desenha centro dos quadrados do tabuleiro:
void Draw_Origin(int id, int x, int y)
{
    if(board[id].busy == true)
        glColor3f(0.0, 1.0, 0.0);
    if(board[id].busy == false)
        glColor3f(1.0, 0.0, 0.0);
    glPointSize(4);
    glBegin(GL_POINTS);
        glVertex3i(x, y, 0);
    glEnd();
}

//Desenha Peças:
//int identificador, char cor, float x, float y, bool dama
void Draw_Checker(int id, int cor, int x_origem, int y_origem, bool dama, int selecionada)
{
    float raio = 1.0, altura = 0.5;
    float x, y;
    float angle = 0.0, angle_stepsize = 0.1;

    float r, g, b;

    /** Draw the tube */
    if(cor==PRETA)
    {
        r = 0.0;
        g = 0.0;
        b = 0.0;

        if(selecionada == 1)
            b = b+0.2;
    }
    if(cor==BRANCA)
    {
        r = 0.6;
        g = 0.6;
        b = 0.6;

        if(selecionada == 1)
            r = r+0.2;
    }
    if(dama)
    {    
        altura = 1.0;
        r += 0.1;
        g += 0.1;
        b += 0.1;
    }
    glColor3f(r, g, b);

    glBegin(GL_QUAD_STRIP);
        angle = 0.0;
        while( angle < 2*PI )
        {
            x = raio * cos(angle);
            y = raio * sin(angle);
            glVertex3f(x + x_origem, y+y_origem , altura);
            glVertex3f(x + x_origem, y+y_origem , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(raio+x_origem, y_origem, altura);
        glVertex3f(raio+x_origem, y_origem, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    if(cor==PRETA)  
    {
        r = 0.1;
        g = 0.1;
        b = 0.1;
        
        if(selecionada == 1)
            b = b+0.2;
    }
    if(cor==BRANCA)
    {
        r = 0.7;
        g = 0.7;
        b = 0.7;
        
        if(selecionada == 1)
            r = r+0.2;
    }
    if(dama)
    {    
        altura = 1.0;
        r += 0.1;
        g += 0.1;
        b += 0.1;
    }

    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        angle = 0.0;
        while( angle < 2*PI )
        {
            x = raio * cos(angle);
            y = raio * sin(angle);
            glVertex3f(x+x_origem, y+y_origem , altura);
            angle = angle + angle_stepsize;
        }
        glVertex3f(raio+x_origem, y_origem, altura);
    glEnd();
}

void Draw_Board_Exterior()
{
    glColor3f(0.55f, 0.3f, 0.22f);
    
    glBegin(GL_QUADS);
        glVertex3i(-10.0, -10.0, 0.0);
        glVertex3i(-10.0, 10.0, 0.0);
        glVertex3i(10.0, 10.0, 0.0);
        glVertex3i(10.0, -10.0, 0.0);
    glEnd();
}

void Draw_Board()
{
    int color = -1;
    glBegin(GL_QUADS);
        for(int x = -8; x < 8; x+=2)
        {
            for(int y = -8; y < 8; y+=2)
            {
                if(color == 1)
                    glColor3f(1.0f, 1.0f, 1.0f);
                else
                    glColor3f(0.0f, 0.0f, 0.0f);
            
                glVertex3f(x,       y,      0.0);
                glVertex3f((x+2),   y,      0.0);
                glVertex3f((x+2),   (y+2),  0.0);
                glVertex3f(x,       (y+2),  0.0);

                color*=-1;
            }
            color*=-1;
        }
    glEnd();
}
