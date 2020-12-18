#pragma once

#include "func.h"

class ch
{
private:
	short col;
	unsigned short Plnow;
	short** desk;
	unsigned short firstX;
	unsigned short firstY;
	unsigned short secondX;
	unsigned short secondY;
	int  beatX;
	int  beatY;
	bool turn;

public:
	ch();
	~ch();

	bool  go();//Основная функция, с которой начинаются проверки.
	//Ввод данных
	void  SetXY(unsigned short x, unsigned short y);
	// Общие функции
	bool  anycan();//проверка на возможность сделать хоть что-то
	void convert();//Функция перевода шашек в дамки по достижению ими соотв. полей

	//Геттеры и Сеттеры.
	short Getdesk(short x, short y) { return desk[y][x]; }//содержимое 1 ячейки на доске.
	short Getcol() { return col; }
	unsigned short GetPlayer() { return Plnow; }// Узнать какой игрок сейчас ходит.
	//Узнать первые и вторые X и Y
	unsigned short GetFX() { return firstX; }
	unsigned short GetFY() { return firstY; }
	unsigned short GetSX() { return secondX; }
	unsigned short GetSY() { return secondY; }
	//Узнать координаты побитой фигуры.
	int  GetBX() { return beatX; }
	int  GetBY() { return beatY; }

private:

	void move();//Ход

	//Проверки для пешки
	void  checker();
	void  checkerhit();//Удар пешкой

   //проверки для дамки
	void  king();
	void  kinghit(short i, short j);//Удар дамкой

   //Задать первые и вторые X и Y
	void SetFX(unsigned short x) { firstX = x; }
	void SetFY(unsigned short y) { firstY = y; }
	void SetSX(unsigned short x) { secondX = x; }
	void SetSY(unsigned short y) { secondY = y; }
	//Задать координаты побитой фигуры.
	void SetBX(unsigned short x) { beatX = x; }
	void SetBY(unsigned short y) { beatY = y; }

	//Проверки на возможность удара
	bool  canhit();//Для всей доски
	bool  CanHitChecker(short i, short j);//Для одной шашки
	bool  CanHitKing(short i, short j);//Для одной дамки
};