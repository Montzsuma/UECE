#pragma comment(lib, "freeglut.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "opengl32.lib")

#include <iostream>
#include <cmath>
#include <windows.h>
#include <GL\glut.h>
#include <map>
#include <algorithm>

//g++ -o main main.cpp -lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "gdi32.lib")

#define LARGURA 600
#define ALTURA 600

#define PRETA 0
#define BRANCA 1

#define DAMA true
#define COMUM false

#define VIVA true
#define MORTA false

#define DESOCUPADA false
#define OCUPADA true

#define SEM_PECA -1

#define CANT 0

#define NORMAL_MOVE_LEFT 1
#define NORMAL_MOVE_RIGHT 2
#define CAPTURE_MOVE_LEFT 3
#define CAPTURE_MOVE_RIGHT 4
#define KING_MOVE_LEFT_DOWN 5
#define KING_MOVE_RIGHT_DOWN 6
#define KING_MOVE_LEFT_UP 7
#define KING_MOVE_RIGHT_UP 8
#define KING_MOVE_LEFT 15
#define KING_MOVE_RIGHT 16

#define PI 3.14159265

using namespace std;

//Include de classes:
#include "checker.h"
#include "board.h"

//Vetores de dados de posições do tabuleiro e peças:
Board board[32];
Checker checker[24];

int KingBlack[4];
int KingWhite[4];

//Vetor para guardar as peças que serão capturadas pela dama:
int vitimas[4];
int capturas;

//Variável para mudança da câmera:
bool is_board_rotated = true;

//Variável para seleção de peças por turno:
bool blacks_turn = true;

//Variáveis para verificar se a peça e a posição foram escolhidas:
bool checker_selected = false;
bool board_selected = false;
int c, b;

//Variáveis do mouse:
double last_press_x = 0, last_press_y = 0;

//Variáveis para rotacionar a câmera durante a troca de turno:
int turn = -1, turn_anim = 0;

//Variáveis para animar as peças:
int move_piece = -1, move_anim = -1, movimento;
int side = 1;

//
int cor = -1;

//Vetor de checagem de teclas:
bool* keyStates = new bool[256];

//Includes:
#include "models.h"
#include "teclado.h"
#include "functions.h"
#include "animation.h"
#include "mouse.h"
#include "tests.h"
#include "drawnimation.h"
#include "initialize.h"
#include "menu.h"

/*

090*0102
50607080
01020304
708090*0
03040506
90*01020
05060708
10203040

*/
