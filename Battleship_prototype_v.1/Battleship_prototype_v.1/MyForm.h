#pragma once
#include<vector>
#include<string>

namespace Battleshipprototypev1 {

	using namespace std;
	using namespace cli;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		cli::array<Button^>^ myMap = gcnew cli::array <Button^>(100);
		cli::array<Button^>^ enemyMap = gcnew cli::array <Button^>(100);
		
		MyForm1(void)
		{
			InitializeComponent();
			buildForm();
		}
		Int32 cellSize = 25;
		
		void buildForm()
		{
			CreateMap();
		}

		void CreateMap()
		{
			this->Size = System::Drawing::Size(cellSize * 10 * 3.5 + 10, cellSize * 10 * 1.7);
			for (int i = 1; i <= 10; i++)
			{
				for (int j = 1; j <= 10; j++)
				{
					Button^ button = gcnew Button();
					button->Size = System::Drawing::Size(cellSize, cellSize);
					button->Location = System::Drawing::Point(cellSize * j, cellSize * i);
					myMap[(i - 1) * 10 + (j - 1)] = button;
					Controls->Add(myMap[(i - 1) * 10 + (j - 1)]);
				}
			}
			//myMap[0]->ForeColor = System::Drawing::Color::Tomato;
			//myMap[0]->BackColor = System::Drawing::Color::Tomato;
			for (int i = 1; i <= 10; i++)
			{
				for (int j = 1; j <= 10; j++)
				{
					Button^ buttonEnemy = gcnew Button();
					buttonEnemy->Size = System::Drawing::Size(cellSize, cellSize);
					buttonEnemy->Location = System::Drawing::Point(cellSize * j+ cellSize * 10 * 2+50, cellSize * i);
					enemyMap[(i - 1) * 10 + (j - 1)] = buttonEnemy;
					Controls->Add(enemyMap[(i - 1) * 10 + (j - 1)]);
				}
			}
		}


	protected:
	
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"MyForm1";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion

		

	
	};
}
