#pragma once
#include <string>
#include <corecrt_math.h>
#define K 8 //Размер доски
#define NONE 0 //Индекс пустой клетки
#define WHITE 0// Индекс белого игрока
#define W 1 // Индекс белого цвета
#define BLACK 2// Индекс черного игрока
#define B -1// Индекс черного игрока
#define CHECKER 1 //Индекс шашки
#define KING 2 //Индекс дамки
#define FP desk[FY][FX] //Содержимое начальной клетки.
#define SP desk[SY] [SX] //Содержимое конечной клетки.
#define FX firstX	//Координаты по X начальной клетки.
#define FY firstY	//Координаты по Y начальной клетки.
#define SX secondX	//Координаты по X конечной клетки.
#define SY secondY	//Координаты по Y конечной клетки.