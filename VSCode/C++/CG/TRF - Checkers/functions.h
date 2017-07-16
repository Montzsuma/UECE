int commonMovement()
{
	//Se a casa escolhida estiver na diagonal up/left...
	if(board[checker[c].id_pos].id_u_left == board[b].id)
		return NORMAL_MOVE_LEFT;
	//Se a casa escolhida estiver na diagonal up/right
	if(board[checker[c].id_pos].id_u_right == board[b].id)
		return NORMAL_MOVE_RIGHT;

	//Verifica se a casa entre a peça e a casa selecionada é a mesma:
	if(board[checker[c].id_pos].id_u_left == board[b].id_d_right)
	{
		//Se a cor da peça selecionada for diferente da cor da peça da casa imediatamente acima e na esquerda:
		//Variável para descobrir a cor da peça que está entre as posições:
		cor = 0;
		//Pego o id da casa que a peça selecionada está...
		cor = checker[c].id_pos;
		//Com o id da casa, pego o id da casa acima/esquerda dela...
		cor = board[cor].id_u_left;
		//Com esse id, pego o id da peça que está nela...
		cor = board[cor].id_checker;

		//Se a casa estiver vazia não existe peça para capturar e o movimento falha.
		if(board[checker[cor].id_pos].busy == DESOCUPADA || cor == SEM_PECA)
			return CANT;
		else
		//Com o id da peça que está na posição entre as a peça e a casa selecionadas, verificamos se ela tem uma cor diferente...
			if(checker[c].cor != checker[cor].cor)
				return CAPTURE_MOVE_LEFT;
			else
				return CANT;
	}
	//Se a casa escolhida estiver na diagonal up/right
	//Verifica se a casa entre a peça e a casa selecionada é a mesma:
	if(board[checker[c].id_pos].id_u_right == board[b].id_d_left)
	{
		//Se a cor da peça selecionada for diferente da cor da peça da casa imediatamente acima e na direita:
		//Variável para descobrir a cor da peça que está entre as posições:
		cor = 0;
		//Pego o id da casa que a peça selecionada está...
		cor = checker[c].id_pos;
		//Com o id da casa, pego o id da casa acima/esquerda dela...
		cor = board[cor].id_u_right;
		//Com esse id, pego o id da peça que está nela...
		cor = board[cor].id_checker;

		if(board[checker[cor].id_pos].busy == DESOCUPADA || cor == SEM_PECA)
			return CANT;
		else
			//Com o id da peça que está na posição entre as a peça e a casa selecionadas, verificamos se ela tem uma cor diferente...
			if(checker[c].cor != checker[cor].cor)
				return CAPTURE_MOVE_RIGHT;
			else
				return CANT;
	}
	return CANT;
}

int kingMovement()
{
	//Variável para verificar quantas peças serão capturadas no movimento da dama e quais são seus ids:
	capturas = 0;
	//Variável para verificar as casas que percorrem o caminho:
	int house = checker[c].id_pos;
	//Verifica se o movimento é para direita:
	if(checker[c].x < board[b].x)
	{
		//Verifica se o movimento é direita/cima:
		if(checker[c].y < board[b].y)
		{
			house = board[house].id_u_right;
			while(house != -1)
			{
				//Se existe uma casa da mesma cor entre a peça e a casa clicada:
				if(checker[board[house].id_checker].cor == checker[c].cor)
					return CANT;
				//Se a peça for de outra cor, o id dela é salvo, e se no final da função o movimento for possível ela será capturada:
				if(checker[board[house].id_checker].cor != checker[c].cor)
				{
					vitimas[capturas] = board[house].id_checker;
					capturas++;
				}
				//Se existem duas casas ocupadas consecutivas:
				if(board[house].busy && board[board[house].id_u_right].busy)
					return CANT;
				//Se alcançamos a casa clicada sem interrupções:
				if(board[house].id == board[b].id)
					return KING_MOVE_RIGHT;
				//Avança a casa sendo verificada:
				house = board[house].id_u_right;
			}
		}
		//Se o movimento não for direita/cima, então é direita/baixo:
		else
		{
			house = board[house].id_d_right;
			while(house != -1)
			{
				//Se existe uma casa da mesma cor entre a peça e a casa clicada:
				if(checker[board[house].id_checker].cor == checker[c].cor)
					return CANT;
				//Se a peça for de outra cor, o id dela é salvo, e se no final da função o movimento for possível ela será capturada:
				if(checker[board[house].id_checker].cor != checker[c].cor)
				{
					vitimas[capturas] = board[house].id_checker;
					capturas++;
				}
				//Se existem duas casas ocupadas consecutivas:
				if(board[house].busy && board[board[house].id_d_right].busy)
					return CANT;
				//Se alcançamos a casa clicada sem interrupções:
				if(board[house].id == board[b].id)
					return KING_MOVE_RIGHT;
				//Avança a casa sendo verificada:
				house = board[house].id_d_right;
			}
		}
	}
	//Se não for para a direita, então é para a esquerda:
	else
	{
		//Verifica se é esquerda/cima:
		if(checker[c].y < board[b].y)
		{
			house = board[house].id_u_left;
			while(house != -1)
			{
				//Se existe uma casa da mesma cor entre a peça e a casa clicada:
				if(checker[board[house].id_checker].cor == checker[c].cor)
					return CANT;
				//Se a peça for de outra cor, o id dela é salvo, e se no final da função o movimento for possível ela será capturada:
				if(checker[board[house].id_checker].cor != checker[c].cor)
				{
					vitimas[capturas] = board[house].id_checker;
					capturas++;
				}
				//Se existem duas casas ocupadas consecutivas:
				if(board[house].busy && board[board[house].id_u_left].busy)
					return CANT;
				//Se alcançamos a casa clicada sem interrupções:
				if(board[house].id == board[b].id)
					return KING_MOVE_LEFT;
				//Avança a casa sendo verificada:
				house = board[house].id_u_left;
			}
		}
		//Verifica se o movimento é esquerda/baixo:
		else
		{
			house = board[house].id_d_left;
			while(house != -1)
			{
				//Se existe uma casa da mesma cor entre a peça e a casa clicada:
				if(checker[board[house].id_checker].cor == checker[c].cor)
					return CANT;
				//Se a peça for de outra cor, o id dela é salvo, e se no final da função o movimento for possível ela será capturada:
				if(checker[board[house].id_checker].cor != checker[c].cor)
				{
					vitimas[capturas] = board[house].id_checker;
					capturas++;
				}
				//Se existem duas casas ocupadas consecutivas:
				if(board[house].busy && board[board[house].id_d_left].busy)
					return CANT;
				//Se alcançamos a casa clicada sem interrupções:
				if(board[house].id == board[b].id)
					return KING_MOVE_LEFT;
				//Avança a casa sendo verificada:
				house = board[house].id_d_left;
			}
		}
	}
}

//Verifica se a peça pode ser movida
int canMove()
{
	//Verifica se a casa selecionada está desocupada...
	if(board[b].busy == DESOCUPADA)
		if(!checker[c].dama)
			return commonMovement();
		else
			return kingMovement();
	else
		return CANT;
}

//Libera a peça e a casa selecionadas:
void release()
{
	board[b].set_selected(false);
	checker[c].set_selected(false);
	checker_selected = false;
	board_selected = false;
}

//Move uma peça comum:
void capture_n_lr()
{
	//Atualiza o estado da casa selecionada para ocupada:
	board[b].set_busy(OCUPADA);
	//Atualiza o id da peça da casa selecionada de SEM_PECA para o id da peça que está sendo movida:
	board[b].set_id_checker(checker[c].id);
	//Muda o estado da casa em que a peça está atualmente para desocupada:
	board[checker[c].id_pos].set_busy(DESOCUPADA);
	//Atualiza o estado da casa em que a peça capturada se encontra:
	board[checker[cor].id_pos].set_busy(DESOCUPADA);
	//Desvinculo a peça que foi capturada a sua casa:
	board[checker[cor].id_pos].set_id_checker(SEM_PECA);
	//Desvinculo a peça a sua casa atual:
	board[checker[c].id_pos].set_id_checker(SEM_PECA);
	//Atualizo as coordenadas xy da peça:
	checker[c].set_xy(board[b].x, board[b].y);
	//Vinculo a peça a nova casa:
	checker[c].set_id_pos(board[b].id);
	//Mata a peça:
	checker[cor].viva = false;
	cor = -1;
}

//Captura uma peça com outra comum:
void move_n_lr()
{
	//Atualiza o estado da casa selecionada para ocupada:
	board[b].set_busy(OCUPADA);
	//Atualiza o id da peça da casa selecionada de -1 para o id da peça que está sendo movida:
	board[b].set_id_checker(checker[c].id);
	//O estado da casa em que a peça está atualmente para desocupada:
	board[checker[c].id_pos].set_busy(DESOCUPADA);
	//Desvinculo a peça a sua casa atual:
	board[checker[c].id_pos].set_id_checker(SEM_PECA);
	//Atualizo as coordenadas xy da peça:
	checker[c].set_xy(board[b].x, board[b].y);
	//Vinculo a peça a nova casa:
	checker[c].set_id_pos(board[b].id);
}

//Captura peças com dama:
void capture_k_lr(int id)
{
	checker[id].viva = MORTA;
	board[checker[id].id_pos].set_busy(false);
	board[checker[id].id_pos].set_id_checker(SEM_PECA);
}

void isKing(int id)
{
	//Recebe a posição da peça selecionada:
	int position = checker[id].id_pos;
	//Verifica a cor da peça e então a transforma em dama se ela estiver em uma casa da extremidade oposta ao seu início:
	if(checker[id].cor == BRANCA)
	{
		for(int j = 0; j < 4; j++)
			if(position == KingWhite[j])
				checker[id].set_king(DAMA);
	}
	if(checker[id].cor == PRETA)
	{
		for(int j = 0; j < 4; j++)
			if(position == KingBlack[j])
				checker[id].set_king(DAMA);
	}
}
