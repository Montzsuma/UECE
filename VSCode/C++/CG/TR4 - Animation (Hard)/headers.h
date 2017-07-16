#include <iostream>
#include <cmath>
#include <windows.h>
#include <glut.h>
#define LARGURA 600
#define ALTURA 600

//Variáveis globais:

//Vetor de checagem de teclas:

bool* keyStates = new bool[256];

//Variáveis de Movimento:

bool pendulo = false;

double translate_x = 0.0;
double translate_y = 0.0;
double translate_z = 0.0;

double grau = 0.0;

double rotate_cube_x = 0.0;
double rotate_cube_y = 0.0;

//Variáveis da Câmera:

bool olhar = false;
bool seguir = false;

double eyex = 0.0;
double eyey = -10.0;
double eyez = 5.0;

double lookx = 0.0;
double looky = 0.0;
double lookz = 1.0;

double upx = 0.0;
double upy = 1.0;
double upz = 1.0;

//Variáveis de Inimigo:

bool enemy = false;

double enemy_a_translate_x = 0.0;
double enemy_a_translate_y = 0.0;
double enemy_b_translate_x = 0.0;
double enemy_b_translate_y = 0.0;

//Includes:

#include "menu.h"
#include "forms.h"
#include "teclado.h"
#include "functions.h"

using namespace std;