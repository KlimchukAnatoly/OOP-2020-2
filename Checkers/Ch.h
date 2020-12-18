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

	bool  go();//�������� �������, � ������� ���������� ��������.
	//���� ������
	void  SetXY(unsigned short x, unsigned short y);
	// ����� �������
	bool  anycan();//�������� �� ����������� ������� ���� ���-��
	void convert();//������� �������� ����� � ����� �� ���������� ��� �����. �����

	//������� � �������.
	short Getdesk(short x, short y) { return desk[y][x]; }//���������� 1 ������ �� �����.
	short Getcol() { return col; }
	unsigned short GetPlayer() { return Plnow; }// ������ ����� ����� ������ �����.
	//������ ������ � ������ X � Y
	unsigned short GetFX() { return firstX; }
	unsigned short GetFY() { return firstY; }
	unsigned short GetSX() { return secondX; }
	unsigned short GetSY() { return secondY; }
	//������ ���������� ������� ������.
	int  GetBX() { return beatX; }
	int  GetBY() { return beatY; }

private:

	void move();//���

	//�������� ��� �����
	void  checker();
	void  checkerhit();//���� ������

   //�������� ��� �����
	void  king();
	void  kinghit(short i, short j);//���� ������

   //������ ������ � ������ X � Y
	void SetFX(unsigned short x) { firstX = x; }
	void SetFY(unsigned short y) { firstY = y; }
	void SetSX(unsigned short x) { secondX = x; }
	void SetSY(unsigned short y) { secondY = y; }
	//������ ���������� ������� ������.
	void SetBX(unsigned short x) { beatX = x; }
	void SetBY(unsigned short y) { beatY = y; }

	//�������� �� ����������� �����
	bool  canhit();//��� ���� �����
	bool  CanHitChecker(short i, short j);//��� ����� �����
	bool  CanHitKing(short i, short j);//��� ����� �����
};