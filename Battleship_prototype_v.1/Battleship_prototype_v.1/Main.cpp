#include "MyForm.h"
#include "EnemyForm.h"
#include "Server.h"
#include <thread>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms;
void main(array <String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Battleshipprototypev1::MyForm1 form1;
	Battleshipprototypev1::EnemyForm form2;
	Application::Run(% form1);

	

}

