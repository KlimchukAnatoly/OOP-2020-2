#include "MyForm.h"
#include "Ch.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(void) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Checkers::MyForm form;
	Application::Run(% form);
}

//Данные
ch game;
short status = 0;

//ВЫХОД
System::Void Checkers::MyForm::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
}
//СДАТЬСЯ
System::Void Checkers::MyForm::GiveUp_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (game.GetPlayer() == BLACK)	MessageBox::Show("ПОБЕДА БЕЛЫХ!", "Черные сдались!");
	else MessageBox::Show("ПОБЕДА ЧЕРНЫХ!", "Белые сдались!");
	Application::Restart();
	return System::Void();
}
//НИЧЬЯ
System::Void Checkers::MyForm::Standoff_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (game.GetPlayer() == BLACK)	MessageBox::Show("Черные предлагают ничью. принять?", "Ничья?");
	else MessageBox::Show("Белые предлагают ничью. принять?", "Ничья?");
	Application::Restart();
	return System::Void();
}
//ПРАВИЛА
System::Void Checkers::MyForm::Rules_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Правила русских шашек:\n"
		"Шашки ходят только по клеткам тёмного цвета.\n"
		"Простая шашка ходит по диагонали вперёд на одну клетку.\n"
		"Простая шашка бьёт вперёд и назад, дамка ходит и бьёт на любое поле диагонали.\n"
		"Дамка бьёт по диагонали, как вперёд, так и назад, и становится на любое свободное поле после побитой шашки.\n"
		"Дамка может бить несколько фигур соперника и должна бить до тех пор, пока это возможно.\n"
		"Взятие обязательно. Если есть возможность продолжить взятие других шашек соперника, то это взятие продолжается,\n"
		"пока бьющая шашка не достигнет положения, из которого бой невозможен.\n"
		"Во время боя простая шашка может превратиться в дамку и сразу продолжить бой по правилам дамки.\n"
		"При наличии нескольких вариантов боя можно выбрать любой из них.\n", "Правила");
	return System::Void();
}
//КНОПКИ
System::Void Checkers::MyForm::B8_Click(System::Object^ sender, System::EventArgs^ e) {
	status = game.SetXY(1, 7, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = B8;
	}
	else if (status == 1) {
		if ( game.Getdesk(1, 7) == KING + WHITE) {
			B8->Image = B8->Image->FromFile(WKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			B8->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		status = 0;
	}
	
	else {
		status = 0;
		if (game.Getdesk(1, 7) == CHECKER + WHITE || game.Getdesk(1, 7) == KING + WHITE) {
			B8->Image = B8->Image->FromFile(WKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			B8->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::D8_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(3, 7, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = D8;
	}
	else if (status == 1) {
		D8->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		if ( game.Getdesk(3, 7) == KING + WHITE) {
			D8->Image = D8->Image->FromFile(WKINGTEX);
		}
		status = 0;
	}
	
	else {
		status = 0;
		D8->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		if ( game.Getdesk(3, 7) == KING + WHITE) {
			D8->Image = D8->Image->FromFile(WKINGTEX);
		}
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::F8_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(5, 7, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = F8;
	}
	else if (status == 1) {
		if (game.Getdesk(5, 7) == KING + WHITE) {
			F8->Image = F8->Image->FromFile(WKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			F8->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}

		status = 0;

	}
	
	else {
		status = 0;
		if (game.Getdesk(5, 7) == KING + WHITE) {
			F8->Image = F8->Image->FromFile(WKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			F8->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::H8_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(7, 7, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = H8;
	}
	else if (status == 1) {
		if (game.Getdesk(7,7)== KING + WHITE) {
			H8->Image = H8->Image->FromFile(WKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			H8->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		status = 0;

	}
	
	else {
		status = 0;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		if (game.Getdesk(7, 7) == KING + WHITE) {
			H8->Image = H8->Image->FromFile(WKINGTEX);
		}
		else if(game.Getdesk(7, 7) == KING + BLACK) {
			H8->Image = H8->Image->FromFile(BKINGTEX);
		}
		else H8->Image = H8->Image->FromFile(BCHECKERTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::A7_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(0, 6, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = A7;
	}
	else if (status == 1) {
		A7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		A7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::C7_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(2, 6, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf->Image = C7->Image;
	}
	else if (status == 1) {
		C7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		C7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::E7_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(4, 6, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = E7;
	}
	else if (status == 1) {
		E7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		E7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::G7_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(6, 6, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = G7;
	}
	else if (status == 1) {
		G7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		G7->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::B6_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(1, 5, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = B6;
	}
	else if (status == 1) {
		B6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		B6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::D6_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(3, 5, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = D6;
	}
	else if (status == 1) {
		D6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		D6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::F6_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(5, 5, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = F6;
	}
	else if (status == 1) {
		F6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {
		status = 0;
		F6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::H6_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(7, 5, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = H6;
	}
	else if (status == 1) {
		H6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		H6->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::A5_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(0, 4, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = A5;
	}
	else if (status == 1) {
		A5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		A5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::C5_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(2, 4, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = C5;
	}
	else if (status == 1) {
		C5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		C5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::E5_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(4, 4, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = E5;
	}
	else if (status == 1) {
		E5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		E5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::G5_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(6, 4, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = G5;
	}
	else if (status == 1) {
		G5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		G5->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::B4_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(1, 3, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = B4;
	}
	else if (status == 1) {
		B4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		B4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::D4_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(3, 3, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = D4;
	}
	else if (status == 1) {
		D4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		D4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::F4_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(5, 3, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = F4;
	}
	else if (status == 1) {
		F4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		F4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::H4_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(7, 3, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = H4;
	}
	else if (status == 1) {
		H4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		H4->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::A3_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(0, 2, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = A3;
	}
	else if (status == 1) {
		A3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		A3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::C3_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(2, 2, status);
	//Произошла ошибка
	if (status == -1) {
		status = 0;
	}
	//Произошла запись 1-х координат
	else if (status == -2) {
		buf = C3;
	}
	//Произошел обычный ход
	else if (status == 1) {
		C3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		C3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::E3_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(4, 2, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = E3;
	}
	else if (status == 1) {
		E3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		E3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::G3_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(6, 2, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = G3;
	}
	else if (status == 1) {
		G3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		G3->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}

	return System::Void();
}
System::Void Checkers::MyForm::B2_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(1, 1, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = B2;
	}
	else if (status == 1) {
		B2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		B2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::D2_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(3, 1, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = D2;
	}
	else if (status == 1) {
		D2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		D2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::F2_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(5, 1, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = F2;
	}
	else if (status == 1) {
		F2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		F2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}

	return System::Void();
}
System::Void Checkers::MyForm::H2_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(7, 1, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = H2;
	}
	else if (status == 1) {
		H2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		status = 0;
	}
	
	else {

		status = 0;
		H2->Image = buf->Image;
		buf->Image = buf->Image->FromFile(VOIDTEX);
		ChangeBeatenTexture();
	}

	return System::Void();
}
System::Void Checkers::MyForm::A1_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(0, 0, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = A1;
	}
	else if (status == 1) {
		if (game.Getdesk(0, 0) == CHECKER + BLACK || game.Getdesk(0, 0) == KING + BLACK) {
			A1->Image = A1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			A1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		status = 0;
	}
	
	else {

		status = 0;
		if (game.Getdesk(0, 0) == CHECKER + BLACK || game.Getdesk(0, 0) == KING + BLACK) {
			A1->Image = A1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			A1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::C1_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(2, 0, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = C1;
	}
	else if (status == 1) {
		if (game.Getdesk(2, 0) == CHECKER + BLACK || game.Getdesk(2, 0) == KING + BLACK) {
			C1->Image = C1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			C1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		status = 0;
	}
	
	else {

		status = 0;
		if (game.Getdesk(2, 0) == CHECKER + BLACK || game.Getdesk(2, 0) == KING + BLACK) {
			C1->Image = C1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			C1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::E1_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(4, 0, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = E1;
	}
	else if (status == 1) {
		if (game.Getdesk(4, 0) == CHECKER + BLACK || game.Getdesk(4, 0) == KING + BLACK) {
			E1->Image = E1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			E1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		status = 0;
	}
	
	else {

		status = 0;
		if (game.Getdesk(4, 0) == CHECKER + BLACK || game.Getdesk(4, 0) == KING + BLACK) {
			E1->Image = E1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			E1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		ChangeBeatenTexture();
	}
	return System::Void();
}
System::Void Checkers::MyForm::G1_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(6, 0, status);
	if (status == -1) {
		status = 0;
	}
	else if (status == -2) {
		buf = G1;
	}
	else if (status == 1) {
		if (game.Getdesk(6, 0) == CHECKER + BLACK || game.Getdesk(6, 0) == KING + BLACK) {
			G1->Image = G1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			G1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		status = 0;
	}
	
	else {
		status = 0;
		if (game.Getdesk(6, 0) == CHECKER + BLACK || game.Getdesk(6, 0) == KING + BLACK) {
			G1->Image = G1->Image->FromFile(BKINGTEX);
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		else {
			G1->Image = buf->Image;
			buf->Image = buf->Image->FromFile(VOIDTEX);
		}
		ChangeBeatenTexture();
	}
	return System::Void();
}

void Checkers::MyForm::ChangeBeatenTexture()
{
	if (game.GetBY() == 0) {
		if (game.GetBX() == 0)A1->Image = A1->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 2)C1->Image = C1->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 4)E1->Image = E1->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 6)G1->Image = G1->Image->FromFile(VOIDTEX);
	}
	else if (game.GetBY() == 1) {
		if (game.GetBX() == 1)B2->Image = B2->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 3)D2->Image = D2->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 5)F2->Image = F2->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 7)H2->Image = H2->Image->FromFile(VOIDTEX);
	}
	else if (game.GetBY() == 2) {
		if (game.GetBX() == 0)A3->Image = A3->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 2)C3->Image = C3->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 4)E3->Image = E3->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 6)G3->Image = G3->Image->FromFile(VOIDTEX);
	}
	else if (game.GetBY() == 3) {
		if (game.GetBX() == 1)B4->Image = B4->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 3)D4->Image = D4->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 5)F4->Image = F4->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 7)H4->Image = H4->Image->FromFile(VOIDTEX);
	}
	else if (game.GetBY() == 4) {
		if (game.GetBX() == 0)A5->Image = A5->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 2)C5->Image = C5->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 4)E5->Image = E5->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 6)G5->Image = G5->Image->FromFile(VOIDTEX);
	}
	else if (game.GetBY() == 5) {
		if (game.GetBX() == 1)B6->Image = B6->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 3)D6->Image = D6->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 5)F6->Image = F6->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 7)H6->Image = H6->Image->FromFile(VOIDTEX);
	}
	else if (game.GetBY() == 6) {
		if (game.GetBX() == 0)A7->Image = A7->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 2)C7->Image = C7->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 4)E7->Image = E7->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 6)G7->Image = G7->Image->FromFile(VOIDTEX);
	}
	else {
		if (game.GetBX() == 1)G1->Image = B8->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 3)G1->Image = D8->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 5)G1->Image = F8->Image->FromFile(VOIDTEX);
		if (game.GetBX() == 7)G1->Image = H8->Image->FromFile(VOIDTEX);
	}
}

void Checkers::MyForm::RefreshTextures()
{
#define CHIMG(x) x->Image=x->Image->FromFile
	if (game.Getdesk(0, 0) == NONE) CHIMG(A1)(VOIDTEX);
	else if (game.Getdesk(0, 0) == BLACK + CHECKER) CHIMG(A1)(BCHECKERTEX);
	else if (game.Getdesk(0, 0) == WHITE + CHECKER) CHIMG(A1)(WCHECKERTEX);
	else if (game.Getdesk(0, 0) == BLACK + KING) CHIMG(A1)(BKINGTEX);
	else CHIMG(A1)(WKINGTEX);

	if (game.Getdesk(0, 2) == NONE) CHIMG(A3)(VOIDTEX);
	else if (game.Getdesk(0, 2) == BLACK + CHECKER) CHIMG(A3)(BCHECKERTEX);
	else if (game.Getdesk(0, 2) == WHITE + CHECKER) CHIMG(A3)(WCHECKERTEX);
	else if (game.Getdesk(0, 2) == BLACK + KING) CHIMG(A3)(BKINGTEX);
	else CHIMG(A3)(WKINGTEX);

	if (game.Getdesk(0, 4) == NONE) CHIMG(A5)(VOIDTEX);
	else if (game.Getdesk(0, 4) == BLACK + CHECKER) CHIMG(A5)(BCHECKERTEX);
	else if (game.Getdesk(0, 4) == WHITE + CHECKER) CHIMG(A5)(WCHECKERTEX);
	else if (game.Getdesk(0, 4) == BLACK + KING) CHIMG(A5)(BKINGTEX);
	else CHIMG(A5)(WKINGTEX);

	if (game.Getdesk(0, 6) == NONE) CHIMG(A7)(VOIDTEX);
	else if (game.Getdesk(0, 6) == BLACK + CHECKER) CHIMG(A7)(BCHECKERTEX);
	else if (game.Getdesk(0, 6) == WHITE + CHECKER) CHIMG(A7)(WCHECKERTEX);
	else if (game.Getdesk(0, 6) == BLACK + KING) CHIMG(A7)(BKINGTEX);
	else CHIMG(A7)(WKINGTEX);

	if (game.Getdesk(1, 1) == NONE) CHIMG(B2)(VOIDTEX);
	else if (game.Getdesk(1, 1) == BLACK + CHECKER) CHIMG(B2)(BCHECKERTEX);
	else if (game.Getdesk(1, 1) == WHITE + CHECKER) CHIMG(B2)(WCHECKERTEX);
	else if (game.Getdesk(1, 1) == BLACK + KING) CHIMG(B2)(BKINGTEX);
	else CHIMG(B2)(WKINGTEX);

	if (game.Getdesk(1, 3) == NONE) CHIMG(B4)(VOIDTEX);
	else if (game.Getdesk(1, 3) == BLACK + CHECKER) CHIMG(B4)(BCHECKERTEX);
	else if (game.Getdesk(1, 3) == WHITE + CHECKER) CHIMG(B4)(WCHECKERTEX);
	else if (game.Getdesk(1, 3) == BLACK + KING) CHIMG(B4)(BKINGTEX);
	else CHIMG(B4)(WKINGTEX);

	if (game.Getdesk(1, 5) == NONE) CHIMG(B6)(VOIDTEX);
	else if (game.Getdesk(1, 5) == BLACK + CHECKER) CHIMG(B6)(BCHECKERTEX);
	else if (game.Getdesk(1, 5) == WHITE + CHECKER) CHIMG(B6)(WCHECKERTEX);
	else if (game.Getdesk(1, 5) == BLACK + KING) CHIMG(B6)(BKINGTEX);
	else CHIMG(B6)(WKINGTEX);

	if (game.Getdesk(1, 7) == NONE) CHIMG(B8)(VOIDTEX);
	else if (game.Getdesk(1, 7) == BLACK + CHECKER) CHIMG(B8)(BCHECKERTEX);
	else if (game.Getdesk(1, 7) == WHITE + CHECKER) CHIMG(B8)(WCHECKERTEX);
	else if (game.Getdesk(1, 7) == BLACK + KING) CHIMG(B8)(BKINGTEX);
	else CHIMG(B8)(WKINGTEX);

	if (game.Getdesk(2, 0) == NONE) CHIMG(C1)(VOIDTEX);
	else if (game.Getdesk(2, 0) == BLACK + CHECKER) CHIMG(C1)(BCHECKERTEX);
	else if (game.Getdesk(2, 0) == WHITE + CHECKER) CHIMG(C1)(WCHECKERTEX);
	else if (game.Getdesk(2, 0) == BLACK + KING) CHIMG(C1)(BKINGTEX);
	else CHIMG(C1)(WKINGTEX);

	if (game.Getdesk(2, 2) == NONE) CHIMG(C3)(VOIDTEX);
	else if (game.Getdesk(2, 2) == BLACK + CHECKER) CHIMG(C3)(BCHECKERTEX);
	else if (game.Getdesk(2, 2) == WHITE + CHECKER) CHIMG(C3)(WCHECKERTEX);
	else if (game.Getdesk(2, 2) == BLACK + KING) CHIMG(C3)(BKINGTEX);
	else CHIMG(C3)(WKINGTEX);

	if (game.Getdesk(2, 4) == NONE) CHIMG(C5)(VOIDTEX);
	else if (game.Getdesk(2, 4) == BLACK + CHECKER) CHIMG(C5)(BCHECKERTEX);
	else if (game.Getdesk(2, 4) == WHITE + CHECKER) CHIMG(C5)(WCHECKERTEX);
	else if (game.Getdesk(2, 4) == BLACK + KING) CHIMG(C5)(BKINGTEX);
	else CHIMG(C5)(WKINGTEX);

	if (game.Getdesk(2, 6) == NONE) CHIMG(C7)(VOIDTEX);
	else if (game.Getdesk(2, 6) == BLACK + CHECKER) CHIMG(C7)(BCHECKERTEX);
	else if (game.Getdesk(2, 6) == WHITE + CHECKER) CHIMG(C7)(WCHECKERTEX);
	else if (game.Getdesk(2, 6) == BLACK + KING) CHIMG(C7)(BKINGTEX);
	else CHIMG(C7)(WKINGTEX);

	if (game.Getdesk(3, 1) == NONE) CHIMG(D2)(VOIDTEX);
	else if (game.Getdesk(3, 1) == BLACK + CHECKER) CHIMG(D2)(BCHECKERTEX);
	else if (game.Getdesk(3, 1) == WHITE + CHECKER) CHIMG(D2)(WCHECKERTEX);
	else if (game.Getdesk(3, 1) == BLACK + KING) CHIMG(D2)(BKINGTEX);
	else CHIMG(D2)(WKINGTEX);

	if (game.Getdesk(3, 3) == NONE) CHIMG(D4)(VOIDTEX);
	else if (game.Getdesk(3, 3) == BLACK + CHECKER) CHIMG(D4)(BCHECKERTEX);
	else if (game.Getdesk(3, 3) == WHITE + CHECKER) CHIMG(D4)(WCHECKERTEX);
	else if (game.Getdesk(3, 3) == BLACK + KING) CHIMG(D4)(BKINGTEX);
	else CHIMG(D4)(WKINGTEX);

	if (game.Getdesk(1, 5) == NONE) CHIMG(D6)(VOIDTEX);
	else if (game.Getdesk(1, 5) == BLACK + CHECKER) CHIMG(D6)(BCHECKERTEX);
	else if (game.Getdesk(1, 5) == WHITE + CHECKER) CHIMG(D6)(WCHECKERTEX);
	else if (game.Getdesk(1, 5) == BLACK + KING) CHIMG(D6)(BKINGTEX);
	else CHIMG(D6)(WKINGTEX);

	if (game.Getdesk(3, 7) == NONE) CHIMG(D8)(VOIDTEX);
	else if (game.Getdesk(3, 7) == BLACK + CHECKER) CHIMG(D8)(BCHECKERTEX);
	else if (game.Getdesk(3, 7) == WHITE + CHECKER) CHIMG(D8)(WCHECKERTEX);
	else if (game.Getdesk(3, 7) == BLACK + KING) CHIMG(D8)(BKINGTEX);
	else CHIMG(D8)(WKINGTEX);

	if (game.Getdesk(4, 7) == NONE) CHIMG(E1)(VOIDTEX);
	else if (game.Getdesk(4, 7) == BLACK + CHECKER) CHIMG(E1)(BCHECKERTEX);
	else if (game.Getdesk(4, 7) == WHITE + CHECKER) CHIMG(E1)(WCHECKERTEX);
	else if (game.Getdesk(4, 7) == BLACK + KING) CHIMG(E1)(BKINGTEX);
	else CHIMG(E1)(WKINGTEX);

	if (game.Getdesk(4, 2) == NONE) CHIMG(E3)(VOIDTEX);
	else if (game.Getdesk(4, 2) == BLACK + CHECKER) CHIMG(E3)(BCHECKERTEX);
	else if (game.Getdesk(4, 2) == WHITE + CHECKER) CHIMG(E3)(WCHECKERTEX);
	else if (game.Getdesk(4, 2) == BLACK + KING) CHIMG(E3)(BKINGTEX);
	else CHIMG(E3)(WKINGTEX);

	if (game.Getdesk(4, 4) == NONE) CHIMG(E5)(VOIDTEX);
	else if (game.Getdesk(4, 4) == BLACK + CHECKER) CHIMG(E5)(BCHECKERTEX);
	else if (game.Getdesk(4, 4) == WHITE + CHECKER) CHIMG(E5)(WCHECKERTEX);
	else if (game.Getdesk(4, 4) == BLACK + KING) CHIMG(E5)(BKINGTEX);
	else CHIMG(E5)(WKINGTEX);


	if (game.Getdesk(4, 6) == NONE) CHIMG(E7)(VOIDTEX);
	else if (game.Getdesk(4, 6) == BLACK + CHECKER) CHIMG(E7)(BCHECKERTEX);
	else if (game.Getdesk(4, 6) == WHITE + CHECKER) CHIMG(E7)(WCHECKERTEX);
	else if (game.Getdesk(4, 6) == BLACK + KING) CHIMG(E7)(BKINGTEX);
	else CHIMG(E7)(WKINGTEX);


	if (game.Getdesk(5, 1) == NONE) CHIMG(F2)(VOIDTEX);
	else if (game.Getdesk(5, 1) == BLACK + CHECKER) CHIMG(F2)(BCHECKERTEX);
	else if (game.Getdesk(5, 1) == WHITE + CHECKER) CHIMG(F2)(WCHECKERTEX);
	else if (game.Getdesk(5, 1) == BLACK + KING) CHIMG(F2)(BKINGTEX);
	else CHIMG(F2)(WKINGTEX);


	if (game.Getdesk(5, 3) == NONE) CHIMG(F4)(VOIDTEX);
	else if (game.Getdesk(5, 3) == BLACK + CHECKER) CHIMG(F4)(BCHECKERTEX);
	else if (game.Getdesk(5, 3) == WHITE + CHECKER) CHIMG(F4)(WCHECKERTEX);
	else if (game.Getdesk(5, 3) == BLACK + KING) CHIMG(F4)(BKINGTEX);
	else CHIMG(F4)(WKINGTEX);


	if (game.Getdesk(5, 5) == NONE) CHIMG(F6)(VOIDTEX);
	else if (game.Getdesk(5, 5) == BLACK + CHECKER) CHIMG(F6)(BCHECKERTEX);
	else if (game.Getdesk(5, 5) == WHITE + CHECKER) CHIMG(F6)(WCHECKERTEX);
	else if (game.Getdesk(5, 5) == BLACK + KING) CHIMG(F6)(BKINGTEX);
	else CHIMG(F6)(WKINGTEX);


	if (game.Getdesk(5, 7) == NONE) CHIMG(F8)(VOIDTEX);
	else if (game.Getdesk(5, 7) == BLACK + CHECKER) CHIMG(F8)(BCHECKERTEX);
	else if (game.Getdesk(5, 7) == WHITE + CHECKER) CHIMG(F8)(WCHECKERTEX);
	else if (game.Getdesk(5, 7) == BLACK + KING) CHIMG(F8)(BKINGTEX);
	else CHIMG(F8)(WKINGTEX);


	if (game.Getdesk(6, 0) == NONE) CHIMG(G1)(VOIDTEX);
	else if (game.Getdesk(6, 0) == BLACK + CHECKER) CHIMG(G1)(BCHECKERTEX);
	else if (game.Getdesk(6, 0) == WHITE + CHECKER) CHIMG(G1)(WCHECKERTEX);
	else if (game.Getdesk(6, 0) == BLACK + KING) CHIMG(G1)(BKINGTEX);
	else CHIMG(G1)(WKINGTEX);


	if (game.Getdesk(6, 2) == NONE) CHIMG(G3)(VOIDTEX);
	else if (game.Getdesk(6, 2) == BLACK + CHECKER) CHIMG(G3)(BCHECKERTEX);
	else if (game.Getdesk(6, 2) == WHITE + CHECKER) CHIMG(G3)(WCHECKERTEX);
	else if (game.Getdesk(6, 2) == BLACK + KING) CHIMG(G3)(BKINGTEX);
	else CHIMG(G3)(WKINGTEX);


	if (game.Getdesk(6, 4) == NONE) CHIMG(G5)(VOIDTEX);
	else if (game.Getdesk(6, 4) == BLACK + CHECKER) CHIMG(G5)(BCHECKERTEX);
	else if (game.Getdesk(6, 4) == WHITE + CHECKER) CHIMG(G5)(WCHECKERTEX);
	else if (game.Getdesk(6, 4) == BLACK + KING) CHIMG(G5)(BKINGTEX);
	else CHIMG(G5)(WKINGTEX);


	if (game.Getdesk(6, 6) == NONE) CHIMG(G7)(VOIDTEX);
	else if (game.Getdesk(6, 6) == BLACK + CHECKER) CHIMG(G7)(BCHECKERTEX);
	else if (game.Getdesk(6, 6) == WHITE + CHECKER) CHIMG(G7)(WCHECKERTEX);
	else if (game.Getdesk(6, 6) == BLACK + KING) CHIMG(G7)(BKINGTEX);
	else CHIMG(G7)(WKINGTEX);


	if (game.Getdesk(7, 1) == NONE) CHIMG(H2)(VOIDTEX);
	else if (game.Getdesk(7, 1) == BLACK + CHECKER) CHIMG(H2)(BCHECKERTEX);
	else if (game.Getdesk(7, 1) == WHITE + CHECKER) CHIMG(H2)(WCHECKERTEX);
	else if (game.Getdesk(7, 1) == BLACK + KING) CHIMG(H2)(BKINGTEX);
	else CHIMG(H2)(WKINGTEX);


	if (game.Getdesk(7, 3) == NONE) CHIMG(H4)(VOIDTEX);
	else if (game.Getdesk(7, 3) == BLACK + CHECKER) CHIMG(H4)(BCHECKERTEX);
	else if (game.Getdesk(7, 3) == WHITE + CHECKER) CHIMG(H4)(WCHECKERTEX);
	else if (game.Getdesk(7, 3) == BLACK + KING) CHIMG(H4)(BKINGTEX);
	else CHIMG(H4)(WKINGTEX);


	if (game.Getdesk(7, 5) == NONE) CHIMG(H6)(VOIDTEX);
	else if (game.Getdesk(7, 5) == BLACK + CHECKER) CHIMG(H6)(BCHECKERTEX);
	else if (game.Getdesk(7, 5) == WHITE + CHECKER) CHIMG(H6)(WCHECKERTEX);
	else if (game.Getdesk(7, 5) == BLACK + KING) CHIMG(H6)(BKINGTEX);
	else CHIMG(H6)(WKINGTEX);


	if (game.Getdesk(7, 7) == NONE) CHIMG(H8)(VOIDTEX);
	else if (game.Getdesk(7, 7) == BLACK + CHECKER) CHIMG(H8)(BCHECKERTEX);
	else if (game.Getdesk(7, 7) == WHITE + CHECKER) CHIMG(H8)(WCHECKERTEX);
	else if (game.Getdesk(7, 7) == BLACK + KING) CHIMG(H8)(BKINGTEX);
	else CHIMG(H8)(WKINGTEX);
#undef CHIMG
}
