/* Callback chamada quando uma tecla é pressionada ou liberada */
void Mouse_Press(int button, int state, int mouse_x, int mouse_y)
{
	//Selecionar peça:
	if(pick_Checker == true)
	{
		if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
		{
			last_press_x = (mouse_x - LARGURA/2.0) / 28.0;
			last_press_y = (ALTURA-mouse_y - ALTURA/2.0) / 28.0;

			//Reseta a distância para cada clique:
			double distance = 9999999999.0;
			//Verifica se na posição clicada tem uma peça:
			for(int i = 0; i < 24; i++)
			{
				//Dist_X = (Xb - Xa)^2
				double dist_x = (last_press_x - checker[i].x)*(last_press_x - checker[i].x);
				//Dist_Y = (Yb - Ya)^2
				double dist_y = (last_press_y - checker[i].y)*(last_press_y - checker[i].y);
				//Distância = raiz(dist_x+dist_y)
				double dist = sqrt(dist_x + dist_y);

				//Verifica a distância calculada é menor que a distância anterior:
				if(dist <= distance && dist < 1.0)
				{
					//Se for, atualiza a distância...
					distance = dist;
					//Libera todas as outras peças...
					for(int j = 0; j < 24; j++)
						checker[j].set_selected(false);
					//E pega a peça com a menor distância atual:
					checker[i].set_selected(true);
					//Pega o id da peça escolhida:
					c = i;
				}
			}

			checker_selected = true;
			pick_Checker = false;

			//cout << "[PEÇA] ID(" << checker[c].id << "), ID_CASA(" << checker[c].id_pos << ")" << endl;
		}
	}
	//Selecionar posição:
	else
	{
		if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
		{
				last_press_x = (mouse_x - LARGURA/2.0) / 28.0;
				last_press_y = (ALTURA-mouse_y - ALTURA/2.0) / 28.0;

				//Reseta a distância para cada clique:
				double distance = 9999999999.0;

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
			pick_Checker = true;
			//cout << "[CASA] ID(" << board[b].id << "), ID_PEÇA(" << board[b].id_checker << ") Ocupada?" << board[b].busy << endl;
		}
	}
}
