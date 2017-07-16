/* Callback chamada quando uma tecla é pressionada ou liberada */
void Mouse_Press(int button, int state, int mouse_x, int mouse_y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		last_press_x = (mouse_x - LARGURA / 2.0) / 28.0;
		last_press_y = (ALTURA - mouse_y - ALTURA / 2.0) / 28.0;

		double distance = 9999999999.0;
		double dist_x;
		double dist_y;
		double dist;

		if(checker_selected == false)
		{
			//Percorre todas as casas jogáveis do tabuleiro:
			for(int i = 0; i < 32; i++)
			{
				//Calcula a distância do clique até a casa que está sendo verificada:
				//Dist_X = (Xb - Xa)^2
				dist_x = (last_press_x - board[i].x)*(last_press_x - board[i].x);
				//Dist_Y = (Yb - Ya)^2
				dist_y = (last_press_y - board[i].y)*(last_press_y - board[i].y);
				//Distância = raiz(dist_x+dist_y)
				dist = sqrt(dist_x + dist_y);

				//Verifica a distância calculada é menor que a distância anterior e se está dentro do raio da casa:
				if(dist <= distance && dist < 1.0)
				{
					//Se for, atualiza a distância...
					distance = dist;
					//Libera todas as outras peças...
					for(int j = 0; j < 24; j++)
						checker[j].set_selected(false);
					
					//Garantimos que uma peça realmente foi escolhida:
					if(board[i].id_checker > -1)
					{
						if(blacks_turn && (checker[board[i].id_checker].cor == PRETA))
						{
							//Pega o id da peça que está na casa escolhida:
							c = board[i].id_checker;
							//Marca a peça como selecionada:
							checker[c].set_selected(true);
							//Peça foi selecionada!
							checker_selected = true;
						}
						if(!blacks_turn && (checker[board[i].id_checker].cor == BRANCA))
						{
							//Pega o id da peça que está na casa escolhida:
							c = board[i].id_checker;
							//Marca a peça como selecionada:
							checker[c].set_selected(true);
							//Peça foi selecionada!
							checker_selected = true;
						}
					}
				}
			}
			//cout << "[PEÇA] ID(" << checker[c].id << "), ID_CASA(" << checker[c].id_pos << ")" << endl;
		}
		else
		{
			if(board_selected == false)
			{
				for(int i = 0; i < 32; i++)
				{
					//Dist_X = (Xb - Xa)^2
					double dist_x = (last_press_x - board[i].x)*(last_press_x - board[i].x);
					//Dist_Y = (Yb - Ya)^2
					double dist_y = (last_press_y - board[i].y)*(last_press_y - board[i].y);
					//Distância = raiz(dist_x+dist_y)
					double dist = sqrt(dist_x + dist_y);

					//Verifica a distância calculada é menor que a distância anterior:
					if(dist <= distance && dist < 1.0)
					{
						//Se for, atualiza a distância...
						distance = dist;
						//Libera todas as outras peças...
						for(int j = 0; j < 32; j++)
							board[j].set_selected(false);
						board[i].set_selected(true);
						//Pega o id da casa escolhida:
						b = i;
					}
				}
				board_selected = true;
			}
			//cout << "[CASA] ID(" << board[b].id << "), ID_PEÇA(" << board[b].id_checker << ") Ocupada?" << board[b].busy << endl;
		}
	}
}
