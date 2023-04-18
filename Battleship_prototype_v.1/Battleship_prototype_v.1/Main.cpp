#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
void main(array <String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Battleshipprototypev1::MyForm1 form;
	Application::Run(% form);
}