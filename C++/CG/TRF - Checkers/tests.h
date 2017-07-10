//Print para testar os caminhos:
void printTest_path()
{
	cout << "Path Test:" << endl;
	for(int u = 0; u < 32; u++)
	{
		cout << board[u].id;
		cout << " up(";
		cout << board[u].id_u_left;
		cout << ", ";
		cout << board[u].id_u_right;
		cout << ") down(";
		cout << board[u].id_d_left;
		cout << ", ";
		cout << board[u].id_d_right;
		cout << ")" << endl;
	}
}

//Print para testar as damas:
void printTest_checkers()
{
	cout << "Checkers Test:" << endl;
	for(int i = 0; i < 24; i++)
	{
		cout << " ID_CHECKER(";
		cout << checker[i].id;
		cout << ") ID_POSITION(";
		cout << checker[i].id_pos;
		cout << ") " << endl;
	}
}

//Print para testar o tabuleiro:
void printTest_Board()
{
	cout << "Board Test:" << endl;
	for(int i = 0; i < 32; i++)
	{
		cout << "ID_POSITION(";
		cout << board[i].id;
		cout << ") ID_CHECKER(";
		cout << board[i].id_checker;
		cout << ") BUSY? ";
		if(board[i].busy)
			cout << "SIM!";
		else
			cout << "NÃO!";
		cout << endl;
	}
}

void printTests()
{
	//Funções para testes.
	printTest_path();

	cout << "#############################################" << endl;

	printTest_checkers();

	cout << "#############################################" << endl;

	printTest_Board();
}
