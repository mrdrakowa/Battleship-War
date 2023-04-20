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
		cli::array<int>^ myMap_int = gcnew cli::array <int>(100);
		cli::array<Button^>^ enemyMap = gcnew cli::array <Button^>(100);

		
		MyForm1(void)
		{
			InitializeComponent();
			for (int i = 0; i < 100; i++)
			{
				myMap_int[i] = 0;
			}
			BuildForm();
			
		}
		Int32 cellSize = 25;
		
		void BuildForm()
		{
			CreateMap();
			GenerateMap();
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
		bool PositionCheck(int x)
		{		
			//Right and Left
				if(x - 1 >= 0)
				if (myMap_int[x-1] != 0)
				{
					return false;
				}
				if(x + 1 < 100)
				if (myMap_int[x+1] != 0)
				{
					return false;
				}

			//Up and Down
				if (x - 10 >= 0)
				if (myMap_int[x - 10] != 0)
				{
					return false;
				}
				if(x + 10 < 100)
				if (myMap_int[x + 10] != 0)
				{
					return false;
				}
			//Up-Left and Down-Right
				if(x-11 >= 0)
				if (myMap_int[x - 11] != 0)
				{
					return false;
				}
				if(x + 11 < 100)
				if (myMap_int[x + 11] != 0)
				{
					return false;
				}
			// Up-Right and Down-Left
				if (x - 9 >= 0)
				if (myMap_int[x - 9] != 0)
				{
					return false;
				}
				if(x + 9 < 100)
				if (myMap_int[x + 9] != 0)
				{
					return false;
				}

			if (myMap_int[x] != 0)
			{
				return false;
			}

			return true;
		}
		void DrawShip(int x)
		{
			
			if (x - 1 >= 0 && x % 10 > 0)
			{
				if (myMap_int[x - 1] != 2)
				{ 
					//myMap[x - 1]->BackColor = System::Drawing::Color::Black;	
					myMap_int[x - 1] = 1;
				}
			}

			if (x + 1 < 100 && x % 10 < 9)
			{
				if (myMap_int[x + 1] != 2)
				{ 
					//myMap[x + 1]->BackColor = System::Drawing::Color::Black;
					myMap_int[x + 1] = 1;
				}
			}
			
			if (x - 10 >= 0)
			{
				if (myMap_int[x - 10] != 2)
				{
					//myMap[x - 10]->BackColor = System::Drawing::Color::Black;
					myMap_int[x - 10] = 1;
				}
			}
			
			if (x + 10 < 100)
			{
				if (myMap_int[x + 10] != 2)
				{ 
				myMap_int[x + 10] = 1;
				//myMap[x + 10]->BackColor = System::Drawing::Color::Black;
			
				}
			}

			if (x - 11 >= 0 && x % 10 > 0)
			{
				myMap_int[x - 11] = 1;
				//myMap[x - 11]->BackColor = System::Drawing::Color::Black;
			}
			if (x + 11 < 100 && x % 10 < 9)
			{
				myMap_int[x + 11] = 1;
				//myMap[x + 11]->BackColor = System::Drawing::Color::Black;
			}
			if (x - 9 >= 0 && x % 10 < 9)
			{
				//myMap[x - 9]->BackColor = System::Drawing::Color::Black;
				myMap_int[x - 9] = 1;
			}
			if (x + 9 < 100 && x % 10 > 0)
			{
				//myMap[x + 9]->BackColor = System::Drawing::Color::Black;
				myMap_int[x + 9] = 1;
			}
		}
		void Generate_1Ships()
		{
			Random^ rand = gcnew Random();
			int ship = 0;
			while (ship < 4)
			{
				int x = rand->Next() % 100;

				if (myMap_int[x] == 0)
				{
					myMap_int[x] = 2;
					DrawShip(x);

					myMap[x]->BackColor = System::Drawing::Color::Aqua;
					ship++;
				}
			}

		}
		void Generate_2Ships()
		{
			Random^ rand = gcnew Random();
			int ship = 0;

			while (ship < 3)
			{
				int x = rand->Next() % 100;
				if (x + 10 < 100)
					if (PositionCheck(x) == true)
						if (PositionCheck(x + 10) == true)
						{
							myMap_int[x] = 2;
							myMap_int[x + 10] = 2;
							DrawShip(x);
							DrawShip(x + 10);
							myMap[x]->BackColor = System::Drawing::Color::Aqua;
							myMap[x + 10]->BackColor = System::Drawing::Color::Aqua;
							ship++;
						}
				if (x % 10 < 9)
					if (PositionCheck(x) == true)
						if (x + 1 < 100)
							if (PositionCheck(x + 1) == true)
							{
								myMap_int[x] = 2;
								myMap_int[x + 1] = 2;
								DrawShip(x);
								DrawShip(x + 1);
								myMap[x]->BackColor = System::Drawing::Color::Aqua;
								myMap[x + 1]->BackColor = System::Drawing::Color::Aqua;
								ship++;
							}
				
			}
		}
		void Generate_3Ships()
		{
			Random^ rand = gcnew Random();
			int ship = 0;
			ship = 0;
			while (ship < 2)
			{
				int x = rand->Next() % 100;
				if(x% 2 == 0)
				if ((x % 10) <= 7)
					if (x + 1 < 100 && x + 2 < 100)								
						if (PositionCheck(x) == true)
							if (PositionCheck(x + 1) == true)
								if (PositionCheck(x + 2) == true)
									{
										myMap_int[x] = 2;
										myMap_int[x + 1] = 2;
										myMap_int[x + 2] = 2;
										DrawShip(x);
										DrawShip(x + 1);
										DrawShip(x + 2);
										myMap[x]->BackColor = System::Drawing::Color::Aqua;
										myMap[x + 1]->BackColor = System::Drawing::Color::Aqua;
										myMap[x + 2]->BackColor = System::Drawing::Color::Aqua;
										ship++;
										continue;
									}
				if (x + 10 < 100)
					if (x + 20 < 100)
						if (PositionCheck(x) == true)
							if (PositionCheck(x + 10) == true)
								if (PositionCheck(x + 20) == true)
								{
									myMap_int[x] = 2;
									myMap_int[x + 10] = 2;
									myMap_int[x + 20] = 2;
									DrawShip(x);
									DrawShip(x + 10);
									DrawShip(x + 20);
									myMap[x]->BackColor = System::Drawing::Color::Aqua;
									myMap[x + 10]->BackColor = System::Drawing::Color::Aqua;
									myMap[x + 20]->BackColor = System::Drawing::Color::Aqua;
									ship++;
								}

			}
		}
		void Generate_4Ships()
		{
			Random^ rand = gcnew Random();
			int ship = 0;
			ship = 0;
			while (ship < 1)
			{
				int x = rand->Next() % 100;
				if (x % 2 == 0)
					if ((x % 10) <= 6)
						if (x + 1 < 100 && x + 2 < 100)
							if(x+3 < 100)
								if(PositionCheck(x+3) == true)
							if (PositionCheck(x) == true)
								if (PositionCheck(x + 1) == true)
									if (PositionCheck(x + 2) == true)
									{
										myMap_int[x] = 2;
										myMap_int[x + 1] = 2;
										myMap_int[x + 2] = 2;
										myMap_int[x + 3] = 2;
										DrawShip(x);
										DrawShip(x + 1);
										DrawShip(x + 2);
										DrawShip(x + 3);
										myMap[x]->BackColor = System::Drawing::Color::Aqua;
										myMap[x + 1]->BackColor = System::Drawing::Color::Aqua;
										myMap[x + 2]->BackColor = System::Drawing::Color::Aqua;
										myMap[x + 3]->BackColor = System::Drawing::Color::Aqua;
										ship++;
										continue;
									}
				if (x + 10 < 100)
					if (x + 20 < 100)
						if (x + 30 < 100)
						if (PositionCheck(x) == true)
							if (PositionCheck(x + 10) == true)
								if (PositionCheck(x + 20) == true)
								if (PositionCheck(x + 30) == true)
								{
									myMap_int[x] = 2;
									myMap_int[x + 10] = 2;
									myMap_int[x + 20] = 2;
									myMap_int[x + 30] = 2;
									DrawShip(x);
									DrawShip(x + 10);
									DrawShip(x + 20);
									DrawShip(x + 30);
									myMap[x]->BackColor = System::Drawing::Color::Aqua;
									myMap[x + 10]->BackColor = System::Drawing::Color::Aqua;
									myMap[x + 20]->BackColor = System::Drawing::Color::Aqua;
									myMap[x + 30]->BackColor = System::Drawing::Color::Aqua;
									ship++;
								}

			}
		}
		void GenerateMap()
		{
			Generate_4Ships();
			Generate_3Ships();
			Generate_2Ships();
			Generate_1Ships();
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
