#pragma once

#define WCHECKERTEX "WChecker.png"
#define BCHECKERTEX "BChecker.png"
#define WKINGTEX "WKing.png"
#define BKINGTEX "BKing.png"
#define VOIDTEX "Void.png"
#define POS  game.Getdesk

namespace Checkers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ Options;
	private: System::Windows::Forms::Button^ Standoff;
	protected:
	private: System::Windows::Forms::Button^ GiveUp;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Label^ Desk;
	private: System::Windows::Forms::Button^ B8;
	private: System::Windows::Forms::Button^ D8;
	private: System::Windows::Forms::Button^ F8;
	private: System::Windows::Forms::Button^ H8;
	private: System::Windows::Forms::Button^ G7;
	private: System::Windows::Forms::Button^ E7;
	private: System::Windows::Forms::Button^ C7;
	private: System::Windows::Forms::Button^ A7;
	private: System::Windows::Forms::Button^ G5;
	private: System::Windows::Forms::Button^ E5;
	private: System::Windows::Forms::Button^ C5;
	private: System::Windows::Forms::Button^ A5;
	private: System::Windows::Forms::Button^ H6;
	private: System::Windows::Forms::Button^ F6;
	private: System::Windows::Forms::Button^ D6;
	private: System::Windows::Forms::Button^ B6;
	private: System::Windows::Forms::Button^ G1;
	private: System::Windows::Forms::Button^ E1;
	private: System::Windows::Forms::Button^ C1;
	private: System::Windows::Forms::Button^ A1;
	private: System::Windows::Forms::Button^ H2;
	private: System::Windows::Forms::Button^ F2;
	private: System::Windows::Forms::Button^ D2;
	private: System::Windows::Forms::Button^ B2;
	private: System::Windows::Forms::Button^ G3;
	private: System::Windows::Forms::Button^ E3;
	private: System::Windows::Forms::Button^ C3;
	private: System::Windows::Forms::Button^ A3;
	private: System::Windows::Forms::Button^ H4;
	private: System::Windows::Forms::Button^ F4;
	private: System::Windows::Forms::Button^ D4;
	private: System::Windows::Forms::Button^ B4;
	private: System::Windows::Forms::Button^ Rules;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Options = (gcnew System::Windows::Forms::GroupBox());
			this->Rules = (gcnew System::Windows::Forms::Button());
			this->Standoff = (gcnew System::Windows::Forms::Button());
			this->GiveUp = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->Desk = (gcnew System::Windows::Forms::Label());
			this->B8 = (gcnew System::Windows::Forms::Button());
			this->D8 = (gcnew System::Windows::Forms::Button());
			this->F8 = (gcnew System::Windows::Forms::Button());
			this->H8 = (gcnew System::Windows::Forms::Button());
			this->G7 = (gcnew System::Windows::Forms::Button());
			this->E7 = (gcnew System::Windows::Forms::Button());
			this->C7 = (gcnew System::Windows::Forms::Button());
			this->A7 = (gcnew System::Windows::Forms::Button());
			this->G5 = (gcnew System::Windows::Forms::Button());
			this->E5 = (gcnew System::Windows::Forms::Button());
			this->C5 = (gcnew System::Windows::Forms::Button());
			this->A5 = (gcnew System::Windows::Forms::Button());
			this->H6 = (gcnew System::Windows::Forms::Button());
			this->F6 = (gcnew System::Windows::Forms::Button());
			this->D6 = (gcnew System::Windows::Forms::Button());
			this->B6 = (gcnew System::Windows::Forms::Button());
			this->G1 = (gcnew System::Windows::Forms::Button());
			this->E1 = (gcnew System::Windows::Forms::Button());
			this->C1 = (gcnew System::Windows::Forms::Button());
			this->A1 = (gcnew System::Windows::Forms::Button());
			this->H2 = (gcnew System::Windows::Forms::Button());
			this->F2 = (gcnew System::Windows::Forms::Button());
			this->D2 = (gcnew System::Windows::Forms::Button());
			this->B2 = (gcnew System::Windows::Forms::Button());
			this->G3 = (gcnew System::Windows::Forms::Button());
			this->E3 = (gcnew System::Windows::Forms::Button());
			this->C3 = (gcnew System::Windows::Forms::Button());
			this->A3 = (gcnew System::Windows::Forms::Button());
			this->H4 = (gcnew System::Windows::Forms::Button());
			this->F4 = (gcnew System::Windows::Forms::Button());
			this->D4 = (gcnew System::Windows::Forms::Button());
			this->B4 = (gcnew System::Windows::Forms::Button());
			this->Options->SuspendLayout();
			this->SuspendLayout();
			// 
			// Options
			// 
			this->Options->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Options.BackgroundImage")));
			this->Options->Controls->Add(this->Rules);
			this->Options->Controls->Add(this->Standoff);
			this->Options->Controls->Add(this->GiveUp);
			this->Options->Controls->Add(this->Exit);
			this->Options->ForeColor = System::Drawing::Color::Orange;
			this->Options->Location = System::Drawing::Point(728, 12);
			this->Options->Margin = System::Windows::Forms::Padding(7, 8, 7, 8);
			this->Options->MinimumSize = System::Drawing::Size(240, 300);
			this->Options->Name = L"Options";
			this->Options->Padding = System::Windows::Forms::Padding(7, 8, 7, 8);
			this->Options->Size = System::Drawing::Size(240, 400);
			this->Options->TabIndex = 0;
			this->Options->TabStop = false;
			this->Options->Text = L"Опции";
			// 
			// Rules
			// 
			this->Rules->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Rules.BackgroundImage")));
			this->Rules->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Rules->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Rules->Location = System::Drawing::Point(10, 189);
			this->Rules->Name = L"Rules";
			this->Rules->Size = System::Drawing::Size(220, 44);
			this->Rules->TabIndex = 3;
			this->Rules->Text = L"Правила";
			this->Rules->UseVisualStyleBackColor = true;
			this->Rules->Click += gcnew System::EventHandler(this, &MyForm::Rules_Click);
			// 
			// Standoff
			// 
			this->Standoff->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Standoff.BackgroundImage")));
			this->Standoff->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Standoff->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Standoff->Location = System::Drawing::Point(10, 139);
			this->Standoff->Name = L"Standoff";
			this->Standoff->Size = System::Drawing::Size(220, 44);
			this->Standoff->TabIndex = 2;
			this->Standoff->Text = L"Ничья";
			this->Standoff->UseVisualStyleBackColor = true;
			this->Standoff->Click += gcnew System::EventHandler(this, &MyForm::Standoff_Click);
			// 
			// GiveUp
			// 
			this->GiveUp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"GiveUp.BackgroundImage")));
			this->GiveUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->GiveUp->ForeColor = System::Drawing::SystemColors::ControlText;
			this->GiveUp->Location = System::Drawing::Point(10, 89);
			this->GiveUp->Name = L"GiveUp";
			this->GiveUp->Size = System::Drawing::Size(220, 44);
			this->GiveUp->TabIndex = 1;
			this->GiveUp->Text = L"Сдаться";
			this->GiveUp->UseVisualStyleBackColor = true;
			this->GiveUp->Click += gcnew System::EventHandler(this, &MyForm::GiveUp_Click);
			// 
			// Exit
			// 
			this->Exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Exit.BackgroundImage")));
			this->Exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Exit->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Exit->Location = System::Drawing::Point(10, 39);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(220, 44);
			this->Exit->TabIndex = 0;
			this->Exit->Text = L"Выход";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &MyForm::Exit_Click);
			// 
			// Desk
			// 
			this->Desk->AutoSize = true;
			this->Desk->BackColor = System::Drawing::SystemColors::ControlText;
			this->Desk->Cursor = System::Windows::Forms::Cursors::Default;
			this->Desk->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Desk.Image")));
			this->Desk->Location = System::Drawing::Point(48, 12);
			this->Desk->MaximumSize = System::Drawing::Size(640, 640);
			this->Desk->MinimumSize = System::Drawing::Size(640, 640);
			this->Desk->Name = L"Desk";
			this->Desk->Size = System::Drawing::Size(640, 640);
			this->Desk->TabIndex = 3;
			// 
			// B8
			// 
			this->B8->BackColor = System::Drawing::Color::Gray;
			this->B8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->B8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->B8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B8.Image")));
			this->B8->Location = System::Drawing::Point(151, 42);
			this->B8->Margin = System::Windows::Forms::Padding(0);
			this->B8->Name = L"B8";
			this->B8->Size = System::Drawing::Size(73, 73);
			this->B8->TabIndex = 4;
			this->B8->UseCompatibleTextRendering = true;
			this->B8->UseVisualStyleBackColor = false;
			this->B8->Click += gcnew System::EventHandler(this, &MyForm::B8_Click);
			// 
			// D8
			// 
			this->D8->BackColor = System::Drawing::Color::Gray;
			this->D8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->D8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->D8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->D8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D8.Image")));
			this->D8->Location = System::Drawing::Point(294, 42);
			this->D8->Margin = System::Windows::Forms::Padding(0);
			this->D8->Name = L"D8";
			this->D8->Size = System::Drawing::Size(73, 73);
			this->D8->TabIndex = 5;
			this->D8->UseCompatibleTextRendering = true;
			this->D8->UseVisualStyleBackColor = false;
			this->D8->Click += gcnew System::EventHandler(this, &MyForm::D8_Click);
			// 
			// F8
			// 
			this->F8->BackColor = System::Drawing::Color::Gray;
			this->F8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->F8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->F8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->F8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F8.Image")));
			this->F8->Location = System::Drawing::Point(438, 42);
			this->F8->Margin = System::Windows::Forms::Padding(0);
			this->F8->Name = L"F8";
			this->F8->Size = System::Drawing::Size(73, 73);
			this->F8->TabIndex = 6;
			this->F8->UseCompatibleTextRendering = true;
			this->F8->UseVisualStyleBackColor = false;
			this->F8->Click += gcnew System::EventHandler(this, &MyForm::F8_Click);
			// 
			// H8
			// 
			this->H8->BackColor = System::Drawing::Color::Gray;
			this->H8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->H8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->H8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->H8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H8.Image")));
			this->H8->Location = System::Drawing::Point(581, 42);
			this->H8->Margin = System::Windows::Forms::Padding(0);
			this->H8->Name = L"H8";
			this->H8->Size = System::Drawing::Size(73, 73);
			this->H8->TabIndex = 7;
			this->H8->UseCompatibleTextRendering = true;
			this->H8->UseVisualStyleBackColor = false;
			this->H8->BackgroundImageChanged += gcnew System::EventHandler(this, &MyForm::H8_Click);
			this->H8->BackgroundImageLayoutChanged += gcnew System::EventHandler(this, &MyForm::H8_Click);
			this->H8->Click += gcnew System::EventHandler(this, &MyForm::H8_Click);
			// 
			// G7
			// 
			this->G7->BackColor = System::Drawing::Color::Gray;
			this->G7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->G7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->G7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->G7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G7.Image")));
			this->G7->Location = System::Drawing::Point(509, 115);
			this->G7->Margin = System::Windows::Forms::Padding(0);
			this->G7->Name = L"G7";
			this->G7->Size = System::Drawing::Size(73, 73);
			this->G7->TabIndex = 11;
			this->G7->UseCompatibleTextRendering = true;
			this->G7->UseVisualStyleBackColor = false;
			this->G7->Click += gcnew System::EventHandler(this, &MyForm::G7_Click);
			// 
			// E7
			// 
			this->E7->BackColor = System::Drawing::Color::Gray;
			this->E7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->E7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->E7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->E7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E7.Image")));
			this->E7->Location = System::Drawing::Point(366, 115);
			this->E7->Margin = System::Windows::Forms::Padding(0);
			this->E7->Name = L"E7";
			this->E7->Size = System::Drawing::Size(73, 73);
			this->E7->TabIndex = 10;
			this->E7->UseCompatibleTextRendering = true;
			this->E7->UseVisualStyleBackColor = false;
			this->E7->Click += gcnew System::EventHandler(this, &MyForm::E7_Click);
			// 
			// C7
			// 
			this->C7->BackColor = System::Drawing::Color::Gray;
			this->C7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->C7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->C7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->C7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C7.Image")));
			this->C7->Location = System::Drawing::Point(222, 115);
			this->C7->Margin = System::Windows::Forms::Padding(0);
			this->C7->Name = L"C7";
			this->C7->Size = System::Drawing::Size(73, 73);
			this->C7->TabIndex = 9;
			this->C7->UseCompatibleTextRendering = true;
			this->C7->UseVisualStyleBackColor = false;
			this->C7->Click += gcnew System::EventHandler(this, &MyForm::C7_Click);
			// 
			// A7
			// 
			this->A7->BackColor = System::Drawing::Color::Gray;
			this->A7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->A7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->A7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->A7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A7.Image")));
			this->A7->Location = System::Drawing::Point(79, 115);
			this->A7->Margin = System::Windows::Forms::Padding(0);
			this->A7->Name = L"A7";
			this->A7->Size = System::Drawing::Size(73, 73);
			this->A7->TabIndex = 8;
			this->A7->UseCompatibleTextRendering = true;
			this->A7->UseVisualStyleBackColor = false;
			this->A7->Click += gcnew System::EventHandler(this, &MyForm::A7_Click);
			// 
			// G5
			// 
			this->G5->BackColor = System::Drawing::Color::Gray;
			this->G5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->G5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->G5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->G5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G5.Image")));
			this->G5->Location = System::Drawing::Point(509, 259);
			this->G5->Margin = System::Windows::Forms::Padding(0);
			this->G5->Name = L"G5";
			this->G5->Size = System::Drawing::Size(73, 73);
			this->G5->TabIndex = 19;
			this->G5->UseCompatibleTextRendering = true;
			this->G5->UseVisualStyleBackColor = false;
			this->G5->Click += gcnew System::EventHandler(this, &MyForm::G5_Click);
			// 
			// E5
			// 
			this->E5->BackColor = System::Drawing::Color::Gray;
			this->E5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->E5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->E5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->E5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E5.Image")));
			this->E5->Location = System::Drawing::Point(366, 259);
			this->E5->Margin = System::Windows::Forms::Padding(0);
			this->E5->Name = L"E5";
			this->E5->Size = System::Drawing::Size(73, 73);
			this->E5->TabIndex = 18;
			this->E5->UseCompatibleTextRendering = true;
			this->E5->UseVisualStyleBackColor = false;
			this->E5->Click += gcnew System::EventHandler(this, &MyForm::E5_Click);
			// 
			// C5
			// 
			this->C5->BackColor = System::Drawing::Color::Gray;
			this->C5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->C5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->C5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->C5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C5.Image")));
			this->C5->Location = System::Drawing::Point(222, 259);
			this->C5->Margin = System::Windows::Forms::Padding(0);
			this->C5->Name = L"C5";
			this->C5->Size = System::Drawing::Size(73, 73);
			this->C5->TabIndex = 17;
			this->C5->UseCompatibleTextRendering = true;
			this->C5->UseVisualStyleBackColor = false;
			this->C5->Click += gcnew System::EventHandler(this, &MyForm::C5_Click);
			// 
			// A5
			// 
			this->A5->BackColor = System::Drawing::Color::Gray;
			this->A5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->A5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->A5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->A5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A5.Image")));
			this->A5->Location = System::Drawing::Point(79, 259);
			this->A5->Margin = System::Windows::Forms::Padding(0);
			this->A5->Name = L"A5";
			this->A5->Size = System::Drawing::Size(73, 73);
			this->A5->TabIndex = 16;
			this->A5->UseCompatibleTextRendering = true;
			this->A5->UseVisualStyleBackColor = false;
			this->A5->Click += gcnew System::EventHandler(this, &MyForm::A5_Click);
			// 
			// H6
			// 
			this->H6->BackColor = System::Drawing::Color::Gray;
			this->H6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->H6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->H6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->H6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H6.Image")));
			this->H6->Location = System::Drawing::Point(581, 186);
			this->H6->Margin = System::Windows::Forms::Padding(0);
			this->H6->Name = L"H6";
			this->H6->Size = System::Drawing::Size(73, 73);
			this->H6->TabIndex = 15;
			this->H6->UseCompatibleTextRendering = true;
			this->H6->UseVisualStyleBackColor = false;
			this->H6->Click += gcnew System::EventHandler(this, &MyForm::H6_Click);
			// 
			// F6
			// 
			this->F6->BackColor = System::Drawing::Color::Gray;
			this->F6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->F6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->F6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->F6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F6.Image")));
			this->F6->Location = System::Drawing::Point(437, 186);
			this->F6->Margin = System::Windows::Forms::Padding(0);
			this->F6->Name = L"F6";
			this->F6->Size = System::Drawing::Size(73, 73);
			this->F6->TabIndex = 14;
			this->F6->UseCompatibleTextRendering = true;
			this->F6->UseVisualStyleBackColor = false;
			this->F6->Click += gcnew System::EventHandler(this, &MyForm::F6_Click);
			// 
			// D6
			// 
			this->D6->BackColor = System::Drawing::Color::Gray;
			this->D6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->D6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->D6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->D6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D6.Image")));
			this->D6->Location = System::Drawing::Point(294, 186);
			this->D6->Margin = System::Windows::Forms::Padding(0);
			this->D6->Name = L"D6";
			this->D6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->D6->Size = System::Drawing::Size(73, 73);
			this->D6->TabIndex = 13;
			this->D6->UseCompatibleTextRendering = true;
			this->D6->UseVisualStyleBackColor = false;
			this->D6->Click += gcnew System::EventHandler(this, &MyForm::D6_Click);
			// 
			// B6
			// 
			this->B6->BackColor = System::Drawing::Color::Gray;
			this->B6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->B6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->B6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B6.Image")));
			this->B6->Location = System::Drawing::Point(150, 186);
			this->B6->Margin = System::Windows::Forms::Padding(0);
			this->B6->Name = L"B6";
			this->B6->Size = System::Drawing::Size(73, 73);
			this->B6->TabIndex = 12;
			this->B6->UseCompatibleTextRendering = true;
			this->B6->UseVisualStyleBackColor = false;
			this->B6->Click += gcnew System::EventHandler(this, &MyForm::B6_Click);
			// 
			// G1
			// 
			this->G1->BackColor = System::Drawing::Color::Gray;
			this->G1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->G1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->G1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->G1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G1.Image")));
			this->G1->Location = System::Drawing::Point(509, 546);
			this->G1->Margin = System::Windows::Forms::Padding(0);
			this->G1->Name = L"G1";
			this->G1->Size = System::Drawing::Size(73, 73);
			this->G1->TabIndex = 35;
			this->G1->UseCompatibleTextRendering = true;
			this->G1->UseVisualStyleBackColor = false;
			this->G1->Click += gcnew System::EventHandler(this, &MyForm::G1_Click);
			// 
			// E1
			// 
			this->E1->BackColor = System::Drawing::Color::Gray;
			this->E1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->E1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->E1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->E1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E1.Image")));
			this->E1->Location = System::Drawing::Point(366, 546);
			this->E1->Margin = System::Windows::Forms::Padding(0);
			this->E1->Name = L"E1";
			this->E1->Size = System::Drawing::Size(73, 73);
			this->E1->TabIndex = 34;
			this->E1->UseCompatibleTextRendering = true;
			this->E1->UseVisualStyleBackColor = false;
			this->E1->Click += gcnew System::EventHandler(this, &MyForm::E1_Click);
			// 
			// C1
			// 
			this->C1->BackColor = System::Drawing::Color::Gray;
			this->C1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->C1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->C1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->C1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C1.Image")));
			this->C1->Location = System::Drawing::Point(222, 546);
			this->C1->Margin = System::Windows::Forms::Padding(0);
			this->C1->Name = L"C1";
			this->C1->Size = System::Drawing::Size(73, 73);
			this->C1->TabIndex = 33;
			this->C1->UseCompatibleTextRendering = true;
			this->C1->UseVisualStyleBackColor = false;
			this->C1->Click += gcnew System::EventHandler(this, &MyForm::C1_Click);
			// 
			// A1
			// 
			this->A1->BackColor = System::Drawing::Color::Gray;
			this->A1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->A1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->A1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->A1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A1.Image")));
			this->A1->Location = System::Drawing::Point(79, 546);
			this->A1->Margin = System::Windows::Forms::Padding(0);
			this->A1->Name = L"A1";
			this->A1->Size = System::Drawing::Size(73, 73);
			this->A1->TabIndex = 32;
			this->A1->UseCompatibleTextRendering = true;
			this->A1->UseVisualStyleBackColor = false;
			this->A1->Click += gcnew System::EventHandler(this, &MyForm::A1_Click);
			// 
			// H2
			// 
			this->H2->BackColor = System::Drawing::Color::Gray;
			this->H2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->H2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->H2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->H2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H2.Image")));
			this->H2->Location = System::Drawing::Point(581, 473);
			this->H2->Margin = System::Windows::Forms::Padding(0);
			this->H2->Name = L"H2";
			this->H2->Size = System::Drawing::Size(73, 73);
			this->H2->TabIndex = 31;
			this->H2->UseCompatibleTextRendering = true;
			this->H2->UseVisualStyleBackColor = false;
			this->H2->Click += gcnew System::EventHandler(this, &MyForm::H2_Click);
			// 
			// F2
			// 
			this->F2->BackColor = System::Drawing::Color::Gray;
			this->F2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->F2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->F2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->F2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F2.Image")));
			this->F2->Location = System::Drawing::Point(437, 473);
			this->F2->Margin = System::Windows::Forms::Padding(0);
			this->F2->Name = L"F2";
			this->F2->Size = System::Drawing::Size(73, 73);
			this->F2->TabIndex = 30;
			this->F2->UseCompatibleTextRendering = true;
			this->F2->UseVisualStyleBackColor = false;
			this->F2->Click += gcnew System::EventHandler(this, &MyForm::F2_Click);
			// 
			// D2
			// 
			this->D2->BackColor = System::Drawing::Color::Gray;
			this->D2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->D2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->D2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->D2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D2.Image")));
			this->D2->Location = System::Drawing::Point(294, 473);
			this->D2->Margin = System::Windows::Forms::Padding(0);
			this->D2->Name = L"D2";
			this->D2->Size = System::Drawing::Size(73, 73);
			this->D2->TabIndex = 29;
			this->D2->UseCompatibleTextRendering = true;
			this->D2->UseVisualStyleBackColor = false;
			this->D2->Click += gcnew System::EventHandler(this, &MyForm::D2_Click);
			// 
			// B2
			// 
			this->B2->BackColor = System::Drawing::Color::Gray;
			this->B2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->B2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->B2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B2.Image")));
			this->B2->Location = System::Drawing::Point(150, 473);
			this->B2->Margin = System::Windows::Forms::Padding(0);
			this->B2->Name = L"B2";
			this->B2->Size = System::Drawing::Size(73, 73);
			this->B2->TabIndex = 28;
			this->B2->UseCompatibleTextRendering = true;
			this->B2->UseVisualStyleBackColor = false;
			this->B2->Click += gcnew System::EventHandler(this, &MyForm::B2_Click);
			// 
			// G3
			// 
			this->G3->BackColor = System::Drawing::Color::Gray;
			this->G3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->G3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->G3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->G3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G3.Image")));
			this->G3->Location = System::Drawing::Point(509, 402);
			this->G3->Margin = System::Windows::Forms::Padding(0);
			this->G3->Name = L"G3";
			this->G3->Size = System::Drawing::Size(73, 73);
			this->G3->TabIndex = 27;
			this->G3->UseCompatibleTextRendering = true;
			this->G3->UseVisualStyleBackColor = false;
			this->G3->Click += gcnew System::EventHandler(this, &MyForm::G3_Click);
			// 
			// E3
			// 
			this->E3->BackColor = System::Drawing::Color::Gray;
			this->E3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->E3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->E3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->E3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E3.Image")));
			this->E3->Location = System::Drawing::Point(366, 402);
			this->E3->Margin = System::Windows::Forms::Padding(0);
			this->E3->Name = L"E3";
			this->E3->Size = System::Drawing::Size(73, 73);
			this->E3->TabIndex = 26;
			this->E3->UseCompatibleTextRendering = true;
			this->E3->UseVisualStyleBackColor = false;
			this->E3->Click += gcnew System::EventHandler(this, &MyForm::E3_Click);
			// 
			// C3
			// 
			this->C3->BackColor = System::Drawing::Color::Gray;
			this->C3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->C3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->C3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->C3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C3.Image")));
			this->C3->Location = System::Drawing::Point(222, 402);
			this->C3->Margin = System::Windows::Forms::Padding(0);
			this->C3->Name = L"C3";
			this->C3->Size = System::Drawing::Size(73, 73);
			this->C3->TabIndex = 25;
			this->C3->UseCompatibleTextRendering = true;
			this->C3->UseVisualStyleBackColor = false;
			this->C3->Click += gcnew System::EventHandler(this, &MyForm::C3_Click);
			// 
			// A3
			// 
			this->A3->BackColor = System::Drawing::Color::Gray;
			this->A3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->A3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->A3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->A3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A3.Image")));
			this->A3->Location = System::Drawing::Point(79, 402);
			this->A3->Margin = System::Windows::Forms::Padding(0);
			this->A3->Name = L"A3";
			this->A3->Size = System::Drawing::Size(73, 73);
			this->A3->TabIndex = 24;
			this->A3->UseCompatibleTextRendering = true;
			this->A3->UseVisualStyleBackColor = false;
			this->A3->Click += gcnew System::EventHandler(this, &MyForm::A3_Click);
			// 
			// H4
			// 
			this->H4->BackColor = System::Drawing::Color::Gray;
			this->H4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->H4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->H4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->H4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H4.Image")));
			this->H4->Location = System::Drawing::Point(582, 330);
			this->H4->Margin = System::Windows::Forms::Padding(0);
			this->H4->Name = L"H4";
			this->H4->Size = System::Drawing::Size(73, 73);
			this->H4->TabIndex = 23;
			this->H4->UseCompatibleTextRendering = true;
			this->H4->UseVisualStyleBackColor = false;
			this->H4->Click += gcnew System::EventHandler(this, &MyForm::H4_Click);
			// 
			// F4
			// 
			this->F4->BackColor = System::Drawing::Color::Gray;
			this->F4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->F4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->F4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->F4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F4.Image")));
			this->F4->Location = System::Drawing::Point(438, 331);
			this->F4->Margin = System::Windows::Forms::Padding(0);
			this->F4->Name = L"F4";
			this->F4->Size = System::Drawing::Size(73, 73);
			this->F4->TabIndex = 22;
			this->F4->UseCompatibleTextRendering = true;
			this->F4->UseVisualStyleBackColor = false;
			this->F4->Click += gcnew System::EventHandler(this, &MyForm::F4_Click);
			// 
			// D4
			// 
			this->D4->BackColor = System::Drawing::Color::Gray;
			this->D4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->D4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->D4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->D4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D4.Image")));
			this->D4->Location = System::Drawing::Point(294, 330);
			this->D4->Margin = System::Windows::Forms::Padding(0);
			this->D4->Name = L"D4";
			this->D4->Size = System::Drawing::Size(73, 73);
			this->D4->TabIndex = 21;
			this->D4->UseCompatibleTextRendering = true;
			this->D4->UseVisualStyleBackColor = false;
			this->D4->Click += gcnew System::EventHandler(this, &MyForm::D4_Click);
			// 
			// B4
			// 
			this->B4->BackColor = System::Drawing::Color::Gray;
			this->B4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->B4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->B4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->B4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B4.Image")));
			this->B4->Location = System::Drawing::Point(150, 330);
			this->B4->Margin = System::Windows::Forms::Padding(0);
			this->B4->Name = L"B4";
			this->B4->Size = System::Drawing::Size(73, 73);
			this->B4->TabIndex = 20;
			this->B4->UseCompatibleTextRendering = true;
			this->B4->UseVisualStyleBackColor = false;
			this->B4->Click += gcnew System::EventHandler(this, &MyForm::B4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Controls->Add(this->G1);
			this->Controls->Add(this->E1);
			this->Controls->Add(this->C1);
			this->Controls->Add(this->A1);
			this->Controls->Add(this->H2);
			this->Controls->Add(this->F2);
			this->Controls->Add(this->D2);
			this->Controls->Add(this->B2);
			this->Controls->Add(this->G3);
			this->Controls->Add(this->E3);
			this->Controls->Add(this->C3);
			this->Controls->Add(this->A3);
			this->Controls->Add(this->H4);
			this->Controls->Add(this->F4);
			this->Controls->Add(this->D4);
			this->Controls->Add(this->B4);
			this->Controls->Add(this->G5);
			this->Controls->Add(this->E5);
			this->Controls->Add(this->C5);
			this->Controls->Add(this->A5);
			this->Controls->Add(this->H6);
			this->Controls->Add(this->F6);
			this->Controls->Add(this->D6);
			this->Controls->Add(this->B6);
			this->Controls->Add(this->G7);
			this->Controls->Add(this->E7);
			this->Controls->Add(this->C7);
			this->Controls->Add(this->A7);
			this->Controls->Add(this->H8);
			this->Controls->Add(this->F8);
			this->Controls->Add(this->D8);
			this->Controls->Add(this->B8);
			this->Controls->Add(this->Desk);
			this->Controls->Add(this->Options);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(7, 8, 7, 8);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Checkers";
			this->Options->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GiveUp_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Standoff_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Rules_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void B8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void D8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void F8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void H8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void A7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void C7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void E7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void G7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void B6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void D6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void F6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void H6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void A5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void C5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void E5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void G5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void B4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void D4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void F4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void H4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void A3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void C3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void E3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void G3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void B2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void D2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void F2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void H2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void A1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void C1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void E1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void G1_Click(System::Object^ sender, System::EventArgs^ e);
private: void RefreshTextures();
};
}
