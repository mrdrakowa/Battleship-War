#pragma once
#include "MyForm.h"
#include "EnemyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int step = 1;

bool Check(int x, int player)
{
	if (player == step)
	{
		if (player == 1)
		{
			step = 2;
		}
		else
		{
			step = 1;
		}

		return true;
	}
	else
	{
		return false;
	}
}