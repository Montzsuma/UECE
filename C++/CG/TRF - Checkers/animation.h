//Rotaciona tabuleiro:
void rotate_board()
{
    checker_selected = false;
    board_selected = false;
    checker[c].set_selected(false);
    board[b].set_selected(false);
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
        if(blacks_turn)
            blacks_turn = false;
        else
            blacks_turn = true;
    }
}

//Move a peça:
void move_checker(int movimento)
{
    //Verifica se o movimento é algum na lista de movimentos para a esquerda:
    if(checker[c].x > board[b].x)
    {
        checker[c].x-=0.25;
        if(checker[c].y < board[b].y)
            checker[c].y+=0.25;
        else
            checker[c].y-=0.25;
    }
    else
    {
        if(checker[c].x < board[b].x)
        {
            checker[c].x+=0.25;
            if(checker[c].y < board[b].y)
                checker[c].y+=0.25;
            else
                checker[c].y-=0.25;
        }
        else
        {
            checker[c].x = board[b].x;
            checker[c].y = board[b].y;
            //Se a peça tiver chegado ao destino...
            //Vemos qual o movimento realizado e atualizamos as casas e peça de acordo.
            if(movimento == NORMAL_MOVE_LEFT || movimento == NORMAL_MOVE_RIGHT)
                move_n_lr();
            if(movimento == CAPTURE_MOVE_LEFT || movimento == CAPTURE_MOVE_RIGHT)
                capture_n_lr();
            if(movimento == KING_MOVE_LEFT || movimento == KING_MOVE_RIGHT)
            {
                for(int i = 0; i < capturas; i++)
                    capture_k_lr(vitimas[i]);
                capturas = 0;
                move_n_lr();
            }
            isKing(c);
            release();

            move_anim*=-1;
            move = -1;
        }
    }
}
