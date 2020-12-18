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
	//������ "���� ����" �����?
	if (!SP) {
		//��� �� ���������?
		if ((FX - SX) == (FY - SY) || (FX - SX) == -(FY - SY)) {
			// ��� ����� ��������� ������?
			if (FP == CHECKER + Plnow) {
				// �������� ������� ���� ��� ����� � �������� ���� ������� ����������.
				return checker();
			}
			// ��� ����� ��������� ������?
			else if (FP == KING + Plnow) {
				// �������� ������� ���� ��� �����
				return king();
			}
			else {
				MessageBox::Show("������ ������ �� ������ ��������!", "������!");
				return -1;
			}
		}
		else {
			MessageBox::Show("� ������ ����� ������ �� ���������!", "������!");
			return -1;
		}
	}
	else {
		MessageBox::Show("������ ������ �� �������� ������!", "������!");
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
			MessageBox::Show("������ ������ �� �� �� ������, � ������� ��������� ��������!", "������");
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
	SP = FP; // ������� �����\����� �� ����� ������
	FP = NONE;// ����������� ������ ������
	Plnow = 2 - Plnow;// ������� ����� ���� � ������� ������
	col = col * (-1);
	convert();
	if (!anycan()) {
		if (Plnow == WHITE) {
			MessageBox::Show("������ ������� ������!", "������!");
			Application::Restart();
		}
		else {
			MessageBox::Show("������ ������ ������!", "������!");
			Application::Restart();
		}
	}
}
bool  ch::anycan() {//�������� �� ����������� ������ ��� ���� ��� ���� ����� 
	if (canhit()) {
		return 1;
	}
	else {
		for (short i = 0; i < K; i += 2) {//������ �� �������
			for (short j = 0; j < K; j += 2) {
				if (desk[i][j] == CHECKER + Plnow) {//��� ���� �����?
					//����� ����� ������?
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
				else if (desk[i][j] == KING + Plnow) {//��� �����?
					//����� ����� ������?
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
		for (short i = 1; i < K; i += 2) {//������ �� �������
			for (short j = 1; j < K; j += 2) {
				if (desk[i][j] == CHECKER + Plnow) {//��� ���� �����?
					//����� ����� ������?
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
				else if (desk[i][j] == KING + Plnow) {//��� �����?
					//����� ����� ������?
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
	//���� ����� ����� �� 7 ������(��� ������ �� 8) - ���������� � �����.
	for (short i = 1; i < K; i += 2) {
		if (desk[7][i] == CHECKER + WHITE) {
			desk[7][i]++;
		}
	}
	//���� ������ ����� �� 0 ������(��� ������ �� 1) - ���������� � �����.
	for (short i = 0; i < K; i += 2) {
		if (desk[0][i] == CHECKER + BLACK) {
			desk[0][i]++;
		}
	}
}

short   ch::checker()// ��� �����
{
	if (SY - FY == 1 * col) {
		//�������� �� ����?	
		if (!canhit())//���� ���
		{
			move();// ����������� �����
			return 1;
		}
		else {
			MessageBox::Show("��� ����������, �� ������ ����!", "������!");
			return -1;
		}
	}
	//����
	else if (abs(SY - FY) == 2) {
		//�������� �� ���������� ����� ����� ������� ����������.
		if ((desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)]) == CHECKER + (2 - Plnow)
			|| (desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)]) == KING + (2 - Plnow)) {
			//���� ������
			checkerhit();
			return 2;
		}
		else {
			MessageBox::Show("�� ��������� ������ ���� ������ ��� ������ ������!", "������!");
			return -1;
		}
	}
	else {
		MessageBox::Show("����� ����� ������ �� 1 ������ ������ ��� ���� ����� ������ �� 2 ������!", "������!");
		return -1;
	}
}
void   ch::checkerhit() {
	SP = FP; // ������� ����� �� ����� ������
	desk[SY - ((SY - FY) / 2)][SX - ((SX - FX) / 2)] = NONE;//����������� ������, ��� ������ ������� ������.
	this->beatX = (SX - ((SX - FX) / 2));
	this->beatY = (SY - ((SY - FY) / 2));
	// ����������� ������ ������
	FP = NONE;
	//��������������� ����� � ����� ���� ��� �������� ��������� ����
	convert();
	// ������� ����� ���� � ������� ������, ���� �� �� ����� ���� �����.
	if (SP == CHECKER + Plnow) {
		if (!CanHitChecker(SY, SX)) {
			Plnow = 2 - Plnow;
			col = col * (-1);
			if (!anycan()) {
				if (Plnow == WHITE) {
					MessageBox::Show("������ ������� ������!", "������!");
					Application::Restart();
				}
				else {
					MessageBox::Show("������ ������ ������!", "������!");
					Application::Restart();
				}
			}

		}
		else {
			MessageBox::Show("�� ������ ���� ������!", "������ �����");
			SX = FX;
			SY = FY;
		}
	}
	//������, ����� ����� ����� ������ ����� ������� ����� �����.
	else {
		if (!CanHitKing(SY, SX)) {
			Plnow = 2 - Plnow;
			col = col * (-1);
			convert();
			if (!anycan()) {
				if (Plnow == WHITE) {
					MessageBox::Show("������ ������� ������!", "������!");
					Application::Restart();
				}
				else {
					MessageBox::Show("������ ������ ������!", "������!");
					Application::Restart();
				}
			}
		}
		else {
			MessageBox::Show("�� ������ ���� ������!", "������ �����");
			SX = FX;
			SY = FY;
		}
	}
}

short  ch::king()
{
	short p;
	short d;
	//���� ���� �� 1 ������ �� ��� �� ����. �������� ������ �� ���.
	if (abs(FY - SY) == 1) {
		//�������� �� ����?	
		if (!canhit())
		{
			move();
			return 1;
		}
		else {
			MessageBox::Show("��� ����������, �� ������ ����!", "������!");
			return -1;
		}
	}
	else if (abs(FX - SX) > 1) {
		short rez = 0, a = 0, b = 0;
		d = (SY - FY) / (abs(SY - FY));
		p = (SX - FX) / (abs(SX - FX));
		//������� ������� ����� ����� �� ���� � �����.
		for (short i = FY + 1 * d, j = FX + 1 * p, c = 0; i != SY, j != SX, c < abs(SX - FX); i += d, j += p, c++)
		{
			if (desk[i][j] == CHECKER + (2 - Plnow) || desk[i][j] == KING + (2 - Plnow)) {
				rez++;
				a = i;
				b = j;
			}
			else if (desk[i][j] == CHECKER + Plnow || desk[i][j] == KING + Plnow) {
				MessageBox::Show("�� ���� �� ������ ���� ����������� �����!", "������!");
				return -1;
			}
		}
		//���� �� ���� ���� ������ ����� - ������ ���.
		if (rez == 0) {
			if (!canhit())
			{
				move();
				return 1;
			}
			else {
				MessageBox::Show("��� ����������, �� ������ ����!", "������!");
				return -1;
			}
		}
		//�� ���� � ����� 1 ����� ����������, ������������ ����.
		if (rez == 1) {
			kinghit(a, b);
			return 2;
		}
		// �� ���� ������ 2 ����� ����������.
		else {
			MessageBox::Show("�� ���� ����� ������ ���� ������ 1 ������ ����������!", "������!");
			return -1;
		}
	}
	else return -1;
}
void  ch::kinghit(short a, short b) {
	// ������� ����� �� ����� ������
	SP = FP;
	//����������� ������, ��� ���� ����� �����.
	desk[a][b] = NONE;
	//������ � ���������
	beatX = b;
	beatY = a;
	// ����������� ������ ������
	FP = NONE;
	convert();
	// ������� ����� ���� � ������� ������, ���� �� �� ����� ���� �����.
	if (!CanHitKing(SY, SX)) {
		Plnow = 2 - Plnow;
		col = col * (-1);
		if (!anycan()) {
			if (Plnow == WHITE) {
				MessageBox::Show("������ ������� ������!", "������!");
				Application::Restart();
			}
			else {
				MessageBox::Show("������ ������ ������!", "������!");
				Application::Restart();
			}
		}

	}
	else {
		MessageBox::Show("�� ������ ���� ������!", "������ �����");
		SX = FX;
		SY = FY;
	}
}

bool  ch::canhit() {// �������� ��� ���� ����� �� ����������� ����. ���� �� ���� �� ������ �� return 1 - ������ �����
	for (short i = 0; i < K; i += 2) {//������ �� �������
		for (short j = 0; j < K; j += 2) {
			if (desk[i][j] == CHECKER + Plnow) {//��� ���� �����?
				if (CanHitChecker(i, j))return 1;//�������� ������� ��� �����
			}
			else if (desk[i][j] == KING + Plnow) {//��� �����?
				if (CanHitKing(i, j))return 1;//�������� ������� ��� �����
			}
		}
	}
	for (short i = 1; i < K; i += 2) {//������ �� �������
		for (short j = 1; j < K; j += 2) {
			if (desk[i][j] == CHECKER + Plnow) {//��� ���� �����?
				if (CanHitChecker(i, j))return 1;//�������� ������� ��� �����
			}
			else if (desk[i][j] == KING + Plnow) {//��� �����?
				if (CanHitKing(i, j))return 1;//�������� ������� ��� �����
			}
		}
	}
	return 0;
}
bool  ch::CanHitChecker(short i, short j) {
	if (i < 6) {//�� ������ �� �� ������� ���� �����?
		if (j < 6) {//�� ������ �� �� ������ ���� �����?
			if (!desk[i + 2][j + 2]) {//����� ������ ������ ��������?
				if (desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow)) {//���� �� ����?
					return 1;
				}
			}
		}
		if (j > 1) {//�� ������ �� �� ����� ���� �����?
			if (!desk[i + 2][j - 2]) {//����� ������ ����� ��������?
				if (desk[i + 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j - 1] == KING + (2 - Plnow)) {//���� �� ����?
					return 1;
				}
			}
		}
	}
	if (i > 1) {//�� ������ �� �� ������ ���� �����?
		if (j < 6) {//�� ������ �� �� ������ ���� �����?
			if (!desk[i - 2][j + 2]) {//����� ������ ������ ��������?
				if (desk[i - 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j + 1] == KING + (2 - Plnow)) {//���� �� ����?
					return 1;//���� ��������, ��� ����������
				}
			}
		}
		if (j > 1) {//�� ������ �� �� ����� ���� �����?
			if (!desk[i - 2][j - 2]) {//����� ������ ����� ��������?
				if (desk[i - 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j - 1] == KING + (2 - Plnow)) {//���� �� ����?
					return 1;//���� ��������, ��� ����������
				}
			}
		}
	}
	return 0;
}
bool  ch::CanHitKing(short i, short j) {
	if (i < 6) {//�� ������ �� �� ������� ���� �����?
		if (j < 6) {//�� ������ �� �� ������ ���� �����?
			for (int k = 0; i + k < 7, j + k < 7; k++) {
				if ((desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow))
					&& !desk[i + k + 1][j + k + 1])
				{//���� ���� ���� � ������ ������ �� ���, ������� 1, �. �. ����� ����.
					return 1;
				}
				else if ((desk[i + 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i + 1][j + 1] == KING + (2 - Plnow))
					&& desk[i + k + 1][j + k + 1])
				{
					break;
				}
			}
			if (j > 1) {//�� ������ �� �� ����� ���� �����?
				for (int k = 0; i + k < 7, j - k >0; k++) {
					if ((desk[i + 1][j - 1] == CHECKER + (2 - Plnow)
						|| desk[i + 1][j - 1] == KING + (2 - Plnow))
						&& !desk[i + k + 1][j - k - 1])
					{//���� ���� ���� � ������ ������ �� ���, ������� 1, �. �. ����� ����.
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
	if (i > 1) {//�� ������ �� �� ������ ���� �����?
		if (j < 6) {//�� ������ �� �� ������ ���� �����?
			for (int k = 0; i - k > 0, j + k < 7; k++) {
				if ((desk[i - 1][j + 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j + 1] == KING + (2 - Plnow))
					&& !desk[i - k - 1][j + k + 1])
				{//���� ���� ���� � ������ ������ �� ���, ������� 1, �. �. ����� ����.
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
		if (j > 1) {//�� ������ �� �� ����� ���� �����?
			for (int k = 0; i - k > 0, j - k > 0; k++) {
				if ((desk[i - 1][j - 1] == CHECKER + (2 - Plnow)
					|| desk[i - 1][j - 1] == KING + (2 - Plnow))
					&& !desk[i - k - 1][j - k - 1])
				{//���� ���� ���� � ������ ������ �� ���, ������� 1, �. �. ����� ����.
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