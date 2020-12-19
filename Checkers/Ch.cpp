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
	turn = 0;

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

bool ch::go() {
	//не ходим ли на клетку где стоим?
	if (!(SY != FY && SY != -FY)) {
		MessageBox::Show("Нельзя ходить на ту же клетку, с которой пытаетесь походить!", "Ошибка");
		return 0;
	}
	//Клетка "куда идти" пуста?
	if (SP) {
		MessageBox::Show("Нельзя ходить на непустую клетку!", "Ошибка!");
		return 0;
	}
	//Ход по диагонали?
	if (!((FX - SX) == (FY - SY) || (FX - SX) == -(FY - SY))) {
		MessageBox::Show("В шашках ходят только по диагонали!", "Ошибка!");
		return 0;
	}
	// это пешка нынешнего игрока?
	if (FP == CHECKER + Plnow) {
		// проверка условий хода для пешки и дейстиве если условия выполнятся.
		checker();
	}
	// это дамка нынешнего игрока?
	else if (FP == KING + Plnow) {
		// проверка условий хода для дамки
		king();
	}
	else {
		MessageBox::Show("Нельзя ходить не своими фигурами!", "Ошибка!");
	}
	return 0;
}

void  ch::SetXY(unsigned short x, unsigned short y)
{
	if (!turn) {
		FX = x;
		FY = y;
	}
	else {
		SX = x;
		SY = y;
		go();
	}
	turn = 1 - turn;
}

void ch::move()
{
	SP = FP; // перенос шашки\дамки на новую клетку
	FP = NONE;// опустошение старой клетки
	Plnow = 2 - Plnow;// переход права хода к другому игроку
	col = -col;
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
		return true;
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
									return true;
								}
							}
							if (j > 0) {
								if (!desk[i + 1][j - 1]) {
									return true;
								}
							}
						}
					}
					else
					{
						if (i > 0) {
							if (j < 7) {
								if (!desk[i - 1][j + 1]) {
									return true;
								}
							}
							if (j > 0) {
								if (!desk[i - 1][j - 1]) {
									return true;
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
								return true;
							}
						}
						if (j > 0) {
							if (!desk[i + 1][j - 1]) {
								return true;
							}
						}
					}
					if (i > 0) {
						if (j < 7) {
							if (!desk[i - 1][j + 1]) {
								return true;
							}
						}
						if (j > 0) {
							if (!desk[i - 1][j - 1]) {
								return true;
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
									return true;
								}
							}
							if (j > 0) {
								if (!desk[i + 1][j - 1]) {
									return true;
								}
							}
						}
					}
					else//Black
					{
						if (i > 0) {
							if (j < 7) {
								if (!desk[i - 1][j + 1]) {
									return true;
								}
							}
							if (j > 0) {
								if (!desk[i - 1][j - 1]) {
									return true;
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
								return true;
							}
						}
						if (j > 0) {
							if (!desk[i + 1][j - 1]) {
								return true;
							}
						}
					}
					if (i > 0) {
						if (j < 7) {
							if (!desk[i - 1][j + 1]) {
								return true;
							}
						}
						if (j > 0) {
							if (!desk[i - 1][j - 1]) {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
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

void   ch::checker()// для Пешек
{
	if (SY - FY == 1 * col) {
		//возможно ли бить?	
		if (!canhit())//если нет
		{
			move();// Перемещение фишки
		}
		else MessageBox::Show("Ход невозможен, вы можете бить!", "Ошибка!");
	}
	//Удар
	else if (abs(SY - FY) == 2) {
		//проверка на враждебную фишку между точками назначения.
		if ((desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)]) == CHECKER + (2 - Plnow)
			|| (desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)]) == KING + (2 - Plnow)) {
			//Удар пешкой
			checkerhit();
		}
		else MessageBox::Show("Вы пытаетесь побить свою фигуру или пустую клетку!", "Ошибка!");
	}
	else MessageBox::Show("Пешка может ходить на 1 клетку вперед или бить через фигуру на 2 клетки!", "Ошибка!");
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

void  ch::king()
{
	short p;
	short d;
	//Если идет на 1 клетку то это не удар. проверка только на ход.
	if (abs(FY - SY) == 1) {
		//возможно ли бить?	
		if (!canhit())
		{
			move();
		}
		else	MessageBox::Show("Ход невозможен, вы можете бить!", "Ошибка!");
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
			}
		}
		//Если на пути нету ничьих фишек - просто ход.
		if (rez == 0) {
			if (!canhit()) {
				move();
			}
			else	MessageBox::Show("Ход невозможен, вы можете бить!", "Ошибка!");
		}
		//На пути у дамки 1 фишка противника, производится удар.
		else if (rez == 1) {
			// на пути больше 2 фишек противника.
			kinghit(a, b);
		}
		else MessageBox::Show("На пути дамки должна быть только 1 фигура противника!", "Ошибка!");
	}
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
				if (CanHitChecker(i, j))return true;//Проверка условий для ШАШКИ
			}
			else if (desk[i][j] == KING + Plnow) {//Это дамка?
				if (CanHitKing(i, j))return true;//Проверка условий для ДАМКИ
			}
		}
	}
	for (short i = 1; i < K; i += 2) {//Проход по массиву
		for (short j = 1; j < K; j += 2) {
			if (desk[i][j] == CHECKER + Plnow) {//Это наша шашка?
				if (CanHitChecker(i, j))return true;//Проверка условий для ШАШКИ
			}
			else if (desk[i][j] == KING + Plnow) {//Это дамка?
				if (CanHitKing(i, j))return true;//Проверка условий для ДАМКИ
			}
		}
	}
	return false;
}
bool  ch::CanHitChecker(short i, short j) {
	if (i < 6) {//Не выйдем ли за верхний край доски?
		if (j < 6) {//Не выйдем ли за правый край доски?
			if (!desk[i + 2][j + 2]) {//через клетку справа свободно?
				if (desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return true;
				}
			}
		}
		if (j > 1) {//Не выйдем ли за левый край доски?
			if (!desk[i + 2][j - 2]) {//через клетку слева свободно?
				if (desk[i + 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j - 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return true;
				}
			}
		}
	}
	if (i > 1) {//Не выйдем ли за нижний край доски?
		if (j < 6) {//Не выйдем ли за правый край доски?
			if (!desk[i - 2][j + 2]) {//через клетку справа свободно?
				if (desk[i - 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j + 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return true;//Бить возможно, ход недоступен
				}
			}
		}
		if (j > 1) {//Не выйдем ли за левый край доски?
			if (!desk[i - 2][j - 2]) {//через клетку слева свободно?
				if (desk[i - 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j - 1] == KING + (2 - Plnow)) {//Есть ли враг?
					return true;//Бить возможно, ход недоступен
				}
			}
		}
	}
	return false;
}
bool  ch::CanHitKing(short i, short j) {
	if (i < 6) {//Не выйдем ли за верхний край доски?
		if (j < 6) {//Не выйдем ли за правый край доски?
			for (int k = 0; i + k < 7, j + k < 7; k++) {
				if ((desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow))
					&& !desk[i + k + 1][j + k + 1])
				{//Если есть враг и пустая клетка за ним, возврат 1, т. к. можно бить.
					return true;
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
						return true;
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
					return true;
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
					return true;
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
	return false;
}