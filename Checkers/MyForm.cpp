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
	game.SetXY(1, 7);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::D8_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(3, 7);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::F8_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(5, 7);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::H8_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(7, 7);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::A7_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(0, 6);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::C7_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(2, 6);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::E7_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(4, 6);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::G7_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(6, 6);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::B6_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(1, 5);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::D6_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(3, 5);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::F6_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(5, 5);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::H6_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(7, 5);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::A5_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(0, 4);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::C5_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(2, 4);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::E5_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(4, 4);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::G5_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(6, 4);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::B4_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(1, 3);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::D4_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(3, 3);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::F4_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(5, 3);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::H4_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(7, 3);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::A3_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(0, 2);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::C3_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(2, 2);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::E3_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(4, 2);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::G3_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(6, 2);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::B2_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(1, 1);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::D2_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(3, 1);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::F2_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(5, 1);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::H2_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(7, 1);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::A1_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(0, 0);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::C1_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(2, 0);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::E1_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(4, 0);
	RefreshTextures();
	return System::Void();
}
System::Void Checkers::MyForm::G1_Click(System::Object^ sender, System::EventArgs^ e)
{
	game.SetXY(6, 0);
	RefreshTextures();
	return System::Void();
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

	if (game.Getdesk(3, 5) == NONE) CHIMG(D6)(VOIDTEX);
	else if (game.Getdesk(3, 5) == BLACK + CHECKER) CHIMG(D6)(BCHECKERTEX);
	else if (game.Getdesk(3, 5) == WHITE + CHECKER) CHIMG(D6)(WCHECKERTEX);
	else if (game.Getdesk(3, 5) == BLACK + KING) CHIMG(D6)(BKINGTEX);
	else CHIMG(D6)(WKINGTEX);

	if (game.Getdesk(3, 7) == NONE) CHIMG(D8)(VOIDTEX);
	else if (game.Getdesk(3, 7) == BLACK + CHECKER) CHIMG(D8)(BCHECKERTEX);
	else if (game.Getdesk(3, 7) == WHITE + CHECKER) CHIMG(D8)(WCHECKERTEX);
	else if (game.Getdesk(3, 7) == BLACK + KING) CHIMG(D8)(BKINGTEX);
	else CHIMG(D8)(WKINGTEX);

	if (game.Getdesk(4, 0) == NONE) CHIMG(E1)(VOIDTEX);
	else if (game.Getdesk(4, 0) == BLACK + CHECKER) CHIMG(E1)(BCHECKERTEX);
	else if (game.Getdesk(4, 0) == WHITE + CHECKER) CHIMG(E1)(WCHECKERTEX);
	else if (game.Getdesk(4, 0) == BLACK + KING) CHIMG(E1)(BKINGTEX);
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