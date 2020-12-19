#pragma once

#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
#include "Menu.h"
class App
{
	static int turnos;
	Menu menu;
	Mundo mundo;
	Imperio imperio;

public :
	App();

	App(Mundo& m, Imperio& I, Menu & menu);

	void MostraMenu();

	Mundo& getMundo();
};

