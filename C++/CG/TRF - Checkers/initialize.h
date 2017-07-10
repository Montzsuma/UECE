//Criar Tabuleiro:
void initialize_board()
{
	int i = 0;
	for(int j = 0; j < 8; j++)
	{
		for(int k = 0; k < 4; k++)
		{
			board[i].set_id(i);
			board[i].set_selected(false);
			board[i].set_reset_ids_up_down();
            board[i].set_id_checker(SEM_PECA);
			if(j % 2 == 0)
				board[i].set_xy(-7+4*k, -7+2*j);
			else
				board[i].set_xy(-5+4*k, -7+2*j);
			if((-7+2*j) == -1 || (-7+2*j) == 1)
				board[i].set_busy(DESOCUPADA);
			else
				board[i].set_busy(OCUPADA);
			i++;
		}
	}
}

//Criar peças:
void initialize_checkers()
{
	int i = 0;
	for(int j = 0; j < 3; j++)
		for(int k = 0; k < 4; k++)
		{
			checker[i].set_id(i);
			checker[i].set_color(PRETA);
			checker[i].set_param(COMUM, VIVA);
			checker[i].set_selected(false);
			checker[i].set_id_pos(i);

			board[i].set_id_checker(i);

			if(j != 1)
				checker[i].set_xy( -7+4*k, -7+2*j);
			else
				checker[i].set_xy(-5+4*k, -7+2*j);
			i++;
		}
	//Criar as peças brancas:
	for(int j = 0; j < 3; j++)
		for(int k = 3; k >= 0; k--)
		{
			checker[i].set_id(i);
			checker[i].set_color(BRANCA);
			checker[i].set_param(COMUM, VIVA);
			checker[i].set_selected(false);
			checker[i].set_id_pos(43-i);

			board[43-i].set_id_checker(i);

			if(j == 1)
				checker[i].set_xy( -7+4*k, 7-2*j);
			else
				checker[i].set_xy(-5+4*k, 7-2*j);
			i++;
		}
}

//Criar caminhos:
void initialize_path()
{
	int i = 0, l, r;
	//Criar a subida:
	for(int j = 0; j < 8; j++)
	{
		for(int k = 0; k < 4; k++)
		{
			if(j % 2 == 0)
			{	l = 3;	r = 4;	}
			else
			{	l = 4;	r = 5;	}
			//Se a casa não estiver na linha de cima...
			if(j != 7)
			{
				if(j % 2 == 0)
				{
					//Se a casa estiver na extremidade esquerda não terá casas a esquerda dela...
					if(k == 0)
						//Liga a casa atual a casa da diagonal direita dela...
						board[i].set_id_u_lr(-1, i+r);
					else
						//Liga a casa atual a casa da diagonal direita e esquerda dela...
						board[i].set_id_u_lr(i+l, i+r);
				}
				else
				{
					//Se a casa estiver na extremidade direita não terá casas a direita dela...
					if(k == 3)
						//Liga a casa atual a casa da diagonal esquerda dela...
						board[i].set_id_u_lr(i+l, -1);
					else
						//Liga a casa atual a casa da diagonal direita e esquerda dela...
						board[i].set_id_u_lr(i+l, i+r);
				}
			}
			i++;
		}
	}

	i = 31;
	//Criar a descida:
	for(int j = 7; j >= 0; j--)
	{
		for(int k = 3; k >= 0; k--)
		{
			if(j % 2 == 0)
			{	l = -5;	r = -4;	}
			else
			{	l = -4;	r = -3;	}
			//Se a casa não estiver na linha de cima...
			if(j != 0)
			{
				if(j % 2 == 0)
				{
					//Se a casa estiver na extremidade esquerda não terá casas a esquerda dela...
					if(k == 0)
						//Liga a casa atual a casa da diagonal direita dela...
						board[i].set_id_d_lr(-1, i+r);
					else
						//Liga a casa atual a casa da diagonal direita e esquerda dela...
						board[i].set_id_d_lr(i+l, i+r);
				}
				else
				{
					//Se a casa estiver na extremidade direita não terá casas a direita dela...
					if(k == 3)
						//Liga a casa atual a casa da diagonal esquerda dela...
						board[i].set_id_d_lr(i+l, -1);
					else
						//Liga a casa atual a casa da diagonal direita e esquerda dela...
						board[i].set_id_d_lr(i+l, i+r);
				}
			}
			i--;
		}
	}
}

void initialize_Kings()
{
    KingBlack[0] = 31;	KingBlack[1] = 30;	KingBlack[2] = 29;	KingBlack[3] = 28;
    KingWhite[0] =  0;	KingWhite[1] =  1;	KingWhite[2] =  2;	KingWhite[3] =  3;
}

//Função para inicializar o tabuleiro, as peças e também para resetar o jogo:
void initialize_world()
{
    //Inicializar casas em que peças se tornam damas:
    initialize_Kings();
	//Resetar tabuleiro:
	initialize_board();
	//Mapear os caminhos no tabuleiro:
	initialize_path();
	//Resetar peças:
	initialize_checkers();
}

void Inicializa (void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, ((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 50.0f);
}
