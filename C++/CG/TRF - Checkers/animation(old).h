//Rotaciona tabuleiro:
void rotate_board()
{
    checker_selected = false;
    board_selected = false;
    turn_anim+=3;
    if(turn_anim > 180)
    {
        turn_anim = 0;
			turn*=-1;
			//Inverter a orientação das peças:
			for(int i = 0; i < 24; i++)
				checker[i].invert_xy();
			//Inverter a orientação das casas:
			for(int i = 0; i < 32; i++)
				board[i].invert_xy();
			//Inverter a orientação dos caminhos:
			for(int i = 0; i < 32; i++)
				board[i].invert_path();
    }
}

//Move a peça:
void move_checker(int movimento)
{
    //Verifica se o movimento é algum na lista de movimentos para a esquerda:
    if(movimento == NORMAL_MOVE_LEFT || movimento == CAPTURE_MOVE_LEFT || movimento == KING_MOVE_LEFT || movimento == KING_CAPTURE_LEFT)
    {
        //Move o xy da peça até que ele se iguale com o xy da casa.
        if(checker[c].x > board[b].x)
        {    
            checker[c].x-=0.5;
            checker[c].y+=0.5;
        }
        else
        {    
            checker[c].x = board[b].x;
            checker[c].y = board[b].y;
        }
        //Se a peça tiver chegado ao destino...
        if(checker[c].x == board[b].x && checker[c].y == board[b].y)
        {
            //Vemos qual o movimento realizado e atualizamos as casas e peça de acordo.
            if(movimento == NORMAL_MOVE_LEFT)
                move_n_lr();
            if(movimento == CAPTURE_MOVE_LEFT)
                //capture_n_lr(CAPTURE_MOVE_LEFT);
                capture_n_lr();
            if(movimento == KING_MOVE_LEFT)
                cout << "moooo" << endl;
            if(movimento == KING_CAPTURE_LEFT)
                cout << "moooo" << endl;
            move_anim*=-1;
            move = -1;
            isKing(c);
            release();
        }
    }
    //Anima para direita:
    //Verifica se o movimento é algum na lista de movimentos para a direita:
    if(movimento == NORMAL_MOVE_RIGHT || movimento == CAPTURE_MOVE_RIGHT || movimento == KING_MOVE_RIGHT || movimento == KING_CAPTURE_RIGHT)
    {
        //Move o xy da peça até que ele se iguale com o xy da casa.
        if(checker[c].x < board[b].x)
        {    
            checker[c].x+=0.5;
            checker[c].y+=0.5;
        }
        else
        {
            checker[c].x = board[b].x;
            checker[c].y = board[b].y;
        }
        //Se a peça tiver chegado ao destino...
        if(checker[c].x == board[b].x && checker[c].y == board[b].y)
        {
            //Vemos qual o movimento realizado e atualizamos as casas e peça de acordo.
            if(movimento == NORMAL_MOVE_RIGHT)
                move_n_lr();
            if(movimento == CAPTURE_MOVE_RIGHT)
                //capture_n_lr(CAPTURE_MOVE_RIGHT);
                capture_n_lr();
            if(movimento == KING_MOVE_RIGHT)
                cout << "moooo" << endl;
            if(movimento == KING_CAPTURE_RIGHT)
                cout << "moooo" << endl;
            move_anim*=-1;
            move = -1;
            isKing(c);
            release();
        }
    }
}
