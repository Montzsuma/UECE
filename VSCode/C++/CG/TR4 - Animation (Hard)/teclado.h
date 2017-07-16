//Inicializa o vetor que verifica o estado da teclas:
void resetKeys()
{
	for(int i = 0; i < 256; i++)
		keyStates[i] = false;
}

//Verifica se uma chave é pressionada:
void KeyDown(unsigned char key, int x, int y)
{
    keyStates[key] = true;
}

//Verifica se uma chave é liberada:
void KeyUp(unsigned char key, int x, int y)
{
    keyStates[key] = false;
}