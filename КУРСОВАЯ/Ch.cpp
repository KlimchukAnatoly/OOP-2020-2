#include "Ch.h"

using namespace System;
using namespace System::Windows::Forms;

ch::ch() {
	Plnow = WHITE;
	col = W;
	FX = 0;
	FY = 0;
	SX = 0;
	SY = 0;
	desk = new short* [K];
	for (short i = 0; i < K; i++) {
		desk[i] = new short[K];
	}

	for (short y = 0; y < K; y++) {
		for (short x = 0; x < K; x++)
		{
			desk[y][x] = 0;
		}
	}

	for (short y = 0; y < 3; y++) {
		for (short x = 0; x < K; x++)
		{
			if ((x + y) % 2 == 0) {
				desk[y][x] = CHECKER + WHITE;
			}
		}
	}

	for (short i = 5; i < K; i++) {
		for (short j = 0; j < K; j++)
		{
			if ((i + j) % 2 == 0) {
				desk[i][j] = CHECKER + BLACK;
			}
		}
	}
	//desk[7] = new short[8]{ 0,3,0,3,0,3,0,3 };
	//desk[6] = new short[8]{ 3,0,3,0,3,0,3,0 };
	//desk[5] = new short[8]{ 0,3,0,3,0,3,0,3 };
	//desk[4] = new short[8]{ 0,0,0,0,0,0,0,0 };
	//desk[3] = new short[8]{ 0,0,0,0,0,0,0,0 };
	//desk[2] = new short[8]{ 1,0,1,0,1,0,1,0 };
	//desk[1] = new short[8]{ 0,1,0,1,0,1,0,1 };
	//desk[0] = new short[8]{ 1,0,1,0,1,0,1,0 };
}
ch::~ch() {
	delete (desk);
}

short ch::go() {
	//Клетка "куда идти" пуста?
	if (!SP) {
		//Ход по диагонали?
		if ((FX - SX) == (FY - SY) || (FX - SX) == -(FY - SY)) {
			// это пешка нынешнего игрока?
			if (FP == CHECKER + Plnow) {
				// проверка условий хода для пешки и дейстиве если условия выполнятся.
				return checker();
			}
			// это дамка нынешнего игрока?
			else if (FP == KING + Plnow) {
				// проверка условий хода для дамки
				return king();
			}
			else {
				MessageBox::Show("Нельзя ходить не своими фигурами!", "Ошибка!");
				return -1;
			}
		}
		else {
			MessageBox::Show("В шашках ходят только по диагонали!", "Ошибка!");
			return -1;
		}
	}
	else {
		MessageBox::Show("Нельзя ходить на непустую клетку!", "Ошибка!");
		return -1;
	}
}

short  ch::SetXY(unsigned short x, unsigned short y, short st)
{
	if (st == 0) {
		FX = x;
		FY = y;

		return -2;
	}
	else {
		SX = x;
		SY = y;
		if (SY != FY && SY != -FY) return go();
		else {
			return -1;
			MessageBox::Show("Нельзя ходить на ту же клетку, с которой пытаетесь походить!", "Ошибка");
		}
	}
}

void ch::refresh() {
	Plnow = WHITE;
	col = W;
	FX = 0;
	FY = 0;
	SX = 0;
	SY = 0;

	for (short y = 0; y < K; y++) {
		for (short x = 0; x < K; x++)
		{
			desk[y][x] = 0;
		}
	}

	for (short y = 0; y < 3; y++) {
		for (short x = 0; x < K; x++)
		{
			if ((x + y) % 2 == 0) {
				desk[y][x] = CHECKER + WHITE;
			}
		}
	}

	for (short i = 5; i < K; i++) {
		for (short j = 0; j < K; j++)
		{
			if ((i + j) % 2 == 0) {
				desk[i][j] = CHECKER + BLACK;
			}
		}
	}
}
void ch::move()
{
	SP = FP; // перенос шашки\дамки на новую клетку
	FP = NONE;// опустошение старой клетки
	Plnow = 2 - Plnow;// переход права хода к другому игроку
	col = col * (-1);
	convert();
	if (!anycan()) {
		if (Plnow == WHITE) {
			MessageBox::Show("Победа ЧЕРНОГО игрока!", "Победа!");
			Application::Restart();
		}
		else {
			MessageBox::Show("Победа БЕЛОГО игрока!", "Победа!");
			Application::Restart();
		}
	}
}
bool  ch::anycan() {//проверка на возможность ходить или бить для всей доски 
	if (canhit()) {
		return 1;
	}
	else {
		for (short i = 0; i < K; i += 2) {//Проход по массиву
			for (short j = 0; j < K; j += 2) {
				if (desk[i][j] == CHECKER + Plnow) {//Это наша шашка?
					//Пешка может ходить?
					if (Plnow == WHITE) {
						if (i < 7) {
							if (j < 7) {
								if (!desk[i + 1][j + 1]) {
									return 1;
								}
							}
							if (j > 0) {
								if (!desk[i + 1][j - 1]) {
									return 1;
								}
							}
						}
					}
					else
					{
						if (i > 0) {
							if (j < 7) {
								if (!desk[i - 1][j + 1]) {
									return 1;
								}
							}
							if (j > 0) {
								if (!desk[i - 1][j - 1]) {
									return 1;
								}
							}
						}
					}
				}
				else if (desk[i][j] == KING + Plnow) {//Это дамка?
					//Дамка может ходить?
					if (i < 7) {
						if (j < 7) {
							if (!desk[i + 1][j + 1]) {
								return 1;
							}
						}
						if (j > 0) {
							if (!desk[i + 1][j - 1]) {
								return 1;
							}
						}
					}
					if (i > 0) {
						if (j < 7) {
							if (!desk[i - 1][j + 1]) {
								return 1;
							}
						}
						if (j > 0) {
							if (!desk[i - 1][j - 1]) {
								return 1;
							}
						}
					}
				}
			}
		}
		for (short i = 1; i < K; i += 2) {//Проход по массиву
			for (short j = 1; j < K; j += 2) {
				if (desk[i][j] == CHECKER + Plnow) {//Это наша шашка?
					//Пешка может ходить?
					if (Plnow == WHITE) {
						if (i < 7) {
							if (j < 7) {
								if (!desk[i + 1][j + 1]) {
									return 1;
								}
							}
							if (j > 0) {
								if (!desk[i + 1][j - 1]) {
									return 1;
								}
							}
						}
					}
					else//Black
					{
						if (i > 0) {
							if (j < 7) {
								if (!desk[i - 1][j + 1]) {
									return 1;
								}
							}
							if (j > 0) {
								if (!desk[i - 1][j - 1]) {
									return 1;
								}
							}
						}
					}
				}
				else if (desk[i][j] == KING + Plnow) {//Это дамка?
					//Дамка может ходить?
					if (i < 7) {
						if (j < 7) {
							if (!desk[i + 1][j + 1]) {
								return 1;
							}
						}
						if (j > 0) {
							if (!desk[i + 1][j - 1]) {
								return 1;
							}
						}
					}
					if (i > 0) {
						if (j < 7) {
							if (!desk[i - 1][j + 1]) {
								return 1;
							}
						}
						if (j > 0) {
							if (!desk[i - 1][j - 1]) {
								return 1;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
void ch::convert() {
	//Если белая шашка на 7 строке(для игрока на 8) - превращаем в дамку.
	for (short i = 1; i < K; i += 2) {
		if (desk[7][i] == CHECKER + WHITE) {
			desk[7][i]++;
		}
	}
	//Если черная шашка на 0 строке(для игрока на 1) - превращаем в дамку.
	for (short i = 0; i < K; i += 2) {
		if (desk[0][i] == CHECKER + BLACK) {
			desk[0][i]++;
		}
	}
}

short   ch::checker()// для Пешек
{
	if (SY - FY == 1 * col) {
		//возможно ли бить?	
		if (!canhit())//если нет
		{
			move();// Перемещение фишки
			return 1;
		}
		else {
			MessageBox::Show("Ход невозможен, вы можете бить!", "Ошибка!");
			return -1;
		}
	}
	//Удар
	else if (abs(SY - FY) == 2) {
		//проверка на враждебную фишку между точками назначения.
		if ((desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)]) == CHECKER + (2 - Plnow)
			|| (desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)]) == KING + (2 - Plnow)) {
			//Удар пешкой
			checkerhit();
			return 2;
		}
		else {
			MessageBox::Show("Вы пытаетесь побить чвою фигуру или пустую клетку!", "Ошибка!");
			return -1;
		}
	}
	else {
		MessageBox::Show("Пешка может ходить на 1 клетку вперед или бить через фигуру на 2 клетки!", "Ошибка!");
		return -1;
	}
}
void   ch::checkerhit() {
	SP = FP; // перенос шашки на новую клетку
	desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)] = NONE;//Опустошение клетки, где стояла побитая фигура.
	this->beatX = (SX - ((SX - FX) / 2));
	this->beatY = (SY - ((SY - FY) / 2));
	// опустошение старой клетки
	FP = NONE;
	//Конвертирование пешки в дамку если она достигла дамочного поля
	convert();
	// Переход права хода к другому игроку, если он не может бить снова.
	if (SP == CHECKER + Plnow) {
		if (!CanHitChecker(SY, SX)) {
			Plnow = 2 - Plnow;
			col = col * (-1);
			if (!anycan()) {
				if (Plnow == WHITE) {
					MessageBox::Show("Победа ЧЕРНОГО игрока!", "Победа!");
					Application::Restart();
				}
				else {
					MessageBox::Show("Победа БЕЛОГО игрока!", "Победа!");
					Application::Restart();
				}
			}

		}
		else {
			MessageBox::Show("Вы можете бить дальше!", "Ходите снова");
			SX = FX;
			SY = FY;
		}
	}
	//Случай, когда шашка стала дамкой после побития фишки врага.
	else {
		if (!CanHitKing(SY, SX)) {
			Plnow = 2 - Plnow;
			col = col * (-1);
			convert();
			if (!anycan()) {
				if (Plnow == WHITE) {
					MessageBox::Show("Победа ЧЕРНОГО игрока!", "Победа!");
					Application::Restart();
				}
				else {
					MessageBox::Show("Победа БЕЛОГО игрока!", "Победа!");
					Application::Restart();
				}
			}
		}
		else {
			MessageBox::Show("Вы можете бить дальше!", "Ходите снова");
			SX = FX;
			SY = FY;
		}
	}
}

short  ch::king()
{
	short p;
	short d;
	//Если идет на 1 клетку то это не удар. проверка только на ход.
	if (abs(FY - SY) == 1) {
		//возможно ли бить?	
		if (!canhit())
		{
			move();
			return 1;
		}
		else {
			MessageBox::Show("Ход невозможен, вы можете бить!", "Ошибка!");
			return -1;
		}
	}
	else if (abs(FX - SX) > 1) {
		short rez = 0, a = 0, b = 0;
		d = (SY - FY) / (abs(SY - FY));
		p = (SX - FX) / (abs(SX - FX));
		//Считаем сколько чужих фигур на пути у дамки.
		for (short i = FY + 1 * d, j = FX + 1 * p, c = 0; i != SY, j != SX, c < abs(SX - FX); i += d, j += p, c++)
		{
			if (desk[i][j] == CHECKER + (2 - Plnow) || desk[i][j] == KING + (2 - Plnow)) {
				rez++;
				a = i;
				b = j;
			}
			else if (desk[i][j] == CHECKER + Plnow || desk[i][j] == KING + Plnow) {
				MessageBox::Show("На пути не должно быть собственных фигур!", "Ошибка!");
				return -1;
			}
		}
		//Если на пути нету ничьих фишек - просто ход.
		if (rez == 0) {
			if (!canhit())
			{
				move();
				return 1;
			}
			else {
				MessageBox::Show("Ход невозможен, вы можете бить!", "Ошибка!");
				return -1;
			}
		}
		//На пути у дамки 1 фишка противника, производится удар.
		if (rez == 1) {
			kinghit(a, b);
			return 2;
		}
		// на пути больше 2 фишек противника.
		else {
			MessageBox::Show("На пути дамки должна быть только 1 фигура противника!", "Ошибка!");
			return -1;
		}
	}
	else return -1;
}
void  ch::kinghit(short a, short b) {
	// перенос шашки на новую клетку
	SP = FP;
	//Опустошение клетки, где была взята шашка.
	desk[a][b] = NONE;
	//Запись её координат
	beatX = b;
	beatY = a;
	// опустошение старой клетки
	FP = NONE;
	convert();
	// переход права хода к другому игроку, если он не может бить снова.
	if (!CanHitKing(SY, SX)) {
		Plnow = 2 - Plnow;
		col = col * (-1);
		if (!anycan()) {
			if (Plnow == WHITE) {
				MessageBox::Show("Победа ЧЕРНОГО игрока!", "Победа!");
				Application::Restart();
			}
			else {
				MessageBox::Show("Победа БЕЛОГО игрока!", "Победа!");
				Application::Restart();
			}
		}

	}
	else {
		MessageBox::Show("Вы можете бить дальше!", "Ходите снова");
		SX = FX;
		SY = FY;
	}
}

bool  ch::canhit() {// Проверки для всей доски на возможность бить. Если ни разу не дойдет до return 1 - ходить можно
	for (short i = 0; i < K; i += 2) {//Проход по массиву
		for (short j = 0; j < K; j += 2) {
			if (desk[i][j] == CHECKER + Plnow) {//Это наша шашка?
				if (CanHitChecker(i, j))return 1;//Проверка условий для ШАШКИ
			}
			else if (desk[i][j] == KING + Plnow) {//Это дамка?
				if (CanHitKing(i, j))return 1;//Проверка условий для ДАМКИ
			}
		}
	}
	for (short i = 1; i < K; i += 2) {//Проход по массиву
		for (short j = 1; j < K; j += 2) {
			if (desk[i][j] == CHECKER + Plnow) {//Это наша шашка?
				if (CanHitChecker(i, j))return 1;//Проверка условий для ШАШКИ
			}
			else if (desk[i][j] == KING + Plnow) {//Это дамка?
				if (CanHitKing(i, j))return 1;//Проверка условий для ДАМКИ
			}
		}
	}
	return 0;
}
bool  ch::CanHitChecker(short i, short j) {
	if (i < 6) {//Не выйдем ли за верхний край доски?
		if (j < 6) {//Не выйдем ли за правый край доски?
			if (!desk[i + 2][j + 2]) {//через клетку справа свободно?
				if (desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return 1;
				}
			}
		}
		if (j > 1) {//Не выйдем ли за левый край доски?
			if (!desk[i + 2][j - 2]) {//через клетку слева свободно?
				if (desk[i + 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j - 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return 1;
				}
			}
		}
	}
	if (i > 1) {//Не выйдем ли за нижний край доски?
		if (j < 6) {//Не выйдем ли за правый край доски?
			if (!desk[i - 2][j + 2]) {//через клетку справа свободно?
				if (desk[i - 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j + 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return 1;//Бить возможно, ход недоступен
				}
			}
		}
		if (j > 1) {//Не выйдем ли за левый край доски?
			if (!desk[i - 2][j - 2]) {//через клетку слева свободно?
				if (desk[i - 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j - 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return 1;//Бить возможно, ход недоступен
				}
			}
		}
	}
	return 0;
}
bool  ch::CanHitKing(short i, short j) {
	if (i < 6) {//Не выйдем ли за верхний край доски?
		if (j < 6) {//Не выйдем ли за правый край доски?
			for (int k = 0; i + k < 7, j + k < 7; k++) {
				if ((desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow))
					&& !desk[i + k + 1][j + k + 1])
				{//Если есть враг и пустая клетка за ним, возврат 1, т. к. можно бить.
					return 1;
				}
				else if ((desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow))
					&& desk[i + k + 1][j + k + 1])
				{
					break;
				}
			}
			if (j > 1) {//Не выйдем ли за левый край доски?
				for (int k = 0; i + k < 7, j - k >0; k++) {
					if ((desk[i + 1][j - 1] == CHECKER + (2 - Plnow)
						|| desk[i + 1][j - 1] == KING + (2 - Plnow))
						&& !desk[i + k + 1][j - k - 1])
					{//Если есть враг и пустая клетка за ним, возврат 1, т. к. можно бить.
						return 1;
					}
					else if ((desk[i + 1][j - 1] == CHECKER + (2 - Plnow)
						|| desk[i + 1][j - 1] == KING + (2 - Plnow))
						&& desk[i + k + 1][j - k - 1])
					{
						break;
					}
				}
			}
		}
	}
	if (i > 1) {//Не выйдем ли за нижний край доски?
		if (j < 6) {//Не выйдем ли за правый край доски?
			for (int k = 0; i - k > 0, j + k < 7; k++) {
				if ((desk[i - 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j + 1] == KING + (2 - Plnow))
					&& !desk[i - k - 1][j + k + 1])
				{//Если есть враг и пустая клетка за ним, возврат 1, т. к. можно бить.
					return 1;
				}
				else if ((desk[i - 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j + 1] == KING + (2 - Plnow))
					&& desk[i - k - 1][j + k + 1])
				{
					break;
				}
			}
		}
		if (j > 1) {//Не выйдем ли за левый край доски?
			for (int k = 0; i - k > 0, j - k > 0; k++) {
				if ((desk[i - 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j - 1] == KING + (2 - Plnow))
					&& !desk[i - k - 1][j - k - 1])
				{//Если есть враг и пустая клетка за ним, возврат 1, т. к. можно бить.
					return 1;
				}
				else if ((desk[i - 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j - 1] == KING + (2 - Plnow))
					&& desk[i - k - 1][j - k - 1])
				{
					break;
				}
			}
		}
	}
	return 0;
}