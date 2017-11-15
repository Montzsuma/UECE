/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	//Câmera fixa
	gluLookAt(0.0, 0.0, 30.0,
			  0.0, 0.0,  0.0,
			  0.0, 1.0,  0.0)
	;

	//Rotaciona o tabuleiro:
	if(is_board_rotated)
		glRotatef(-30, 1.0, 0.0, 0.0);

	glRotatef(turn_anim, 0.0, 0.0, 1.0);
	
	//Desenha tabuleiro:
	Draw_Board_Exterior();
	Draw_Board();

	//Desenha peças:
	for(int i = 0; i < 24; i++)
	{
        //Desenha a peça apenas se ela estiver viva:
        if(checker[i].viva)
            Draw_Checker(	checker[i].id,
                            checker[i].cor,
                            checker[i].x,
                            checker[i].y,
                            checker[i].dama,
                            checker[i].select)
            ;
	}
	//Desenha casas:

	/*
	for(int i = 0; i < 32; i++)
	{
        //Desenha a peça apenas se ela estiver viva:
		Draw_Origin(	board[i].id,
						board[i].x,
						board[i].y)
		;
	}
	*/
	
	glutSwapBuffers();
}

void Anima(int value)
{
	//Rotacionar ao apertar ENTER:
	//Garante que a última rotação foi completada antes de se iniciar uma nova:
	if(turn_anim == 0)
		if(keyStates[13])
			turn*=-1;
	if(turn==1)
		rotate_board();

	//Verifica se uma peça e uma casa foram escolhidas, se sim iniciamos o movimento, se não liberamos a peça e a casa.
	if(move_piece == -1)
	{
		if(checker_selected && board_selected)
		{
			movimento = canMove();
			if(movimento == CANT)
				release();
			else
			{
				move_piece = 1;
				move_anim*=-1;
			}
		}
	}
	if(move_anim == 1)
		move_checker(movimento);

	glutPostRedisplay();
	glutTimerFunc(1000.0/60.0, Anima, ++value);
}
