#include "MyForm.h"
#include "EnemyForm.h"
//#include "Server.h"

using namespace System;
using namespace Threading;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms;
void main(array <String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Battleshipprototypev1::MyForm1 form1;
	Battleshipprototypev1::EnemyForm form2;
	
	form2.Show();
	Application::Run(% form1);
	

}

