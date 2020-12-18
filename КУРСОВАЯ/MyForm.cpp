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

//Äàííûå
ch game;
short status = 0;

//ÂÛÕÎÄ
System::Void Checkers::MyForm::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
}
//ÑÄÀÒÜÑß
System::Void Checkers::MyForm::GiveUp_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (game.GetPlayer() == BLACK)	MessageBox::Show("ÏÎÁÅÄÀ ÁÅËÛÕ!", "×åðíûå ñäàëèñü!");
	else MessageBox::Show("ÏÎÁÅÄÀ ×ÅÐÍÛÕ!", "Áåëûå ñäàëèñü!");
	Application::Restart();
	return System::Void();
}
//ÍÈ×Üß
System::Void Checkers::MyForm::Standoff_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (game.GetPlayer() == BLACK)	MessageBox::Show("×åðíûå ïðåäëàãàþò íè÷üþ. ïðèíÿòü?", "Íè÷üÿ?");
	else MessageBox::Show("Áåëûå ïðåäëàãàþò íè÷üþ. ïðèíÿòü?", "Íè÷üÿ?");
	Application::Restart();
	return System::Void();
}
//ÏÐÀÂÈËÀ
System::Void Checkers::MyForm::Rules_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Ïðàâèëà ðóññêèõ øàøåê:\n"
		"Øàøêè õîäÿò òîëüêî ïî êëåòêàì ò¸ìíîãî öâåòà.\n"
		"Ïðîñòàÿ øàøêà õîäèò ïî äèàãîíàëè âïåð¸ä íà îäíó êëåòêó.\n"
		"Ïðîñòàÿ øàøêà áü¸ò âïåð¸ä è íàçàä, äàìêà õîäèò è áü¸ò íà ëþáîå ïîëå äèàãîíàëè.\n"
		"Äàìêà áü¸ò ïî äèàãîíàëè, êàê âïåð¸ä, òàê è íàçàä, è ñòàíîâèòñÿ íà ëþáîå ñâîáîäíîå ïîëå ïîñëå ïîáèòîé øàøêè.\n"
		"Äàìêà ìîæåò áèòü íåñêîëüêî ôèãóð ñîïåðíèêà è äîëæíà áèòü äî òåõ ïîð, ïîêà ýòî âîçìîæíî.\n"
		"Âçÿòèå îáÿçàòåëüíî. Åñëè åñòü âîçìîæíîñòü ïðîäîëæèòü âçÿòèå äðóãèõ øàøåê ñîïåðíèêà, òî ýòî âçÿòèå ïðîäîëæàåòñÿ,\n"
		"ïîêà áüþùàÿ øàøêà íå äîñòèãíåò ïîëîæåíèÿ, èç êîòîðîãî áîé íåâîçìîæåí.\n"
		"Âî âðåìÿ áîÿ ïðîñòàÿ øàøêà ìîæåò ïðåâðàòèòüñÿ â äàìêó è ñðàçó ïðîäîëæèòü áîé ïî ïðàâèëàì äàìêè.\n"
		"Ïðè íàëè÷èè íåñêîëüêèõ âàðèàíòîâ áîÿ ìîæíî âûáðàòü ëþáîé èç íèõ.\n", "Ïðàâèëà");
	return System::Void();
}
//ÊÍÎÏÊÈ
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
			B8->BackgroundImage = B8->BackgroundImage->FromFile(WKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			B8->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {
		status = 0;
		if (game.Getdesk(1, 7) == CHECKER + WHITE || game.Getdesk(1, 7) == KING + WHITE) {
			B8->BackgroundImage = B8->BackgroundImage->FromFile(WKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			B8->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}
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
		D8->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if ( game.Getdesk(3, 7) == KING + WHITE) {
			D8->BackgroundImage = D8->BackgroundImage->FromFile(WKINGTEX);
		}
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {
		status = 0;
		D8->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if ( game.Getdesk(3, 7) == KING + WHITE) {
			D8->BackgroundImage = D8->BackgroundImage->FromFile(WKINGTEX);
		}
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
			F8->BackgroundImage = F8->BackgroundImage->FromFile(WKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			F8->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}

		status = 0;

	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {
		status = 0;
		if (game.Getdesk(5, 7) == KING + WHITE) {
			F8->BackgroundImage = F8->BackgroundImage->FromFile(WKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			F8->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}
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
			H8->BackgroundImage = H8->BackgroundImage->FromFile(WKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			H8->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		status = 0;

	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {
		status = 0;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.Getdesk(7, 7) == KING + WHITE) {
			H8->BackgroundImage = H8->BackgroundImage->FromFile(WKINGTEX);
		}
		else if(game.Getdesk(7, 7) == KING + BLACK) {
			H8->BackgroundImage = H8->BackgroundImage->FromFile(BKINGTEX);
		}
		else H8->BackgroundImage = H8->BackgroundImage->FromFile(BCHECKERTEX);
	
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}
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
		A7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		A7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		buf = C7;
	}
	else if (status == 1) {
		C7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		C7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		E7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		E7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		G7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		G7->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		B6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		B6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		D6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		D6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		F6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {
		status = 0;
		F6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		H6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		H6->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		A5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		A5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		C5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		C5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		E5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		E5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		G5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		G5->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		B4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		B4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		D4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		D4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		F4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		F4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		H4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		H4->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		A3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		A3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

	}
	return System::Void();
}
System::Void Checkers::MyForm::C3_Click(System::Object^ sender, System::EventArgs^ e)
{
	status = game.SetXY(2, 2, status);
	//Ïðîèçîøëà îøèáêà
	if (status == -1) {
		status = 0;
	}
	//Ïðîèçîøëà çàïèñü 1-õ êîîðäèíàò
	else if (status == -2) {
		buf = C3;
	}
	//Ïðîèçîøåë îáû÷íûé õîä
	else if (status == 1) {
		C3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		C3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		E3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		E3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		G3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		G3->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		B2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		B2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		D2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		D2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		F2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		F2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
		H2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		H2->BackgroundImage = buf->BackgroundImage;
		buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}

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
			A1->BackgroundImage = A1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			A1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		if (game.Getdesk(0, 0) == CHECKER + BLACK || game.Getdesk(0, 0) == KING + BLACK) {
			A1->BackgroundImage = A1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			A1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}
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
			C1->BackgroundImage = C1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			C1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		if (game.Getdesk(2, 0) == CHECKER + BLACK || game.Getdesk(2, 0) == KING + BLACK) {
			C1->BackgroundImage = C1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			C1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}
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
			E1->BackgroundImage = E1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			E1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {

		status = 0;
		if (game.Getdesk(4, 0) == CHECKER + BLACK || game.Getdesk(4, 0) == KING + BLACK) {
			E1->BackgroundImage = E1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			E1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}
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
			G1->BackgroundImage = G1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			G1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		status = 0;
	}
	//ÏÐÎÈÑÕÎÄÈÒ ÓÄÀÐ, Î×ÅÍÜ ÌÍÎÃÎ ÓÑËÎÂÈÉ ÄËß ÇÀÌÅÍÛ ÒÅÊÑÒÓÐÛ ÏÎÁÈÒÎÉ ØÀØÊÈ
	else {
		status = 0;
		if (game.Getdesk(6, 0) == CHECKER + BLACK || game.Getdesk(6, 0) == KING + BLACK) {
			G1->BackgroundImage = G1->BackgroundImage->FromFile(BKINGTEX);
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			G1->BackgroundImage = buf->BackgroundImage;
			buf->BackgroundImage = buf->BackgroundImage->FromFile(VOIDTEX);
		}
		if (game.GetBY() == 0) {
			if (game.GetBX() == 0)A1->BackgroundImage = A1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C1->BackgroundImage = C1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E1->BackgroundImage = E1->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G1->BackgroundImage = G1->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 1) {
			if (game.GetBX() == 1)B2->BackgroundImage = B2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D2->BackgroundImage = D2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F2->BackgroundImage = F2->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H2->BackgroundImage = H2->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 2) {
			if (game.GetBX() == 0)A3->BackgroundImage = A3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C3->BackgroundImage = C3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E3->BackgroundImage = E3->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G3->BackgroundImage = G3->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 3) {
			if (game.GetBX() == 1)B4->BackgroundImage = B4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D4->BackgroundImage = D4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F4->BackgroundImage = F4->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H4->BackgroundImage = H4->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 4) {
			if (game.GetBX() == 0)A5->BackgroundImage = A5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C5->BackgroundImage = C5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E5->BackgroundImage = E5->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G5->BackgroundImage = G5->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 5) {
			if (game.GetBX() == 1)B6->BackgroundImage = B6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)D6->BackgroundImage = D6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)F6->BackgroundImage = F6->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)H6->BackgroundImage = H6->BackgroundImage->FromFile(VOIDTEX);
		}
		else if (game.GetBY() == 6) {
			if (game.GetBX() == 0)A7->BackgroundImage = A7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 2)C7->BackgroundImage = C7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 4)E7->BackgroundImage = E7->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 6)G7->BackgroundImage = G7->BackgroundImage->FromFile(VOIDTEX);
		}
		else {
			if (game.GetBX() == 1)G1->BackgroundImage = B8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 3)G1->BackgroundImage = D8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 5)G1->BackgroundImage = F8->BackgroundImage->FromFile(VOIDTEX);
			if (game.GetBX() == 7)G1->BackgroundImage = H8->BackgroundImage->FromFile(VOIDTEX);
		}
	}
	return System::Void();
}
