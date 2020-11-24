// Trabalho POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include "Mundo.h"
#include "Menu.h"
using namespace std;

int main()
{
	// const string testf = "territorios.txt";
	Mundo m = Mundo();
	vector<string> menuValues;

	menuOpt opt = Menu::verMenu(menuValues);
	switch (opt)
	{
	case menuOpt::CarregaFich:
		if (m.LerFich(menuValues[0])) {
			m.listaTerritorios();
		}
		break;
	case menuOpt::Cria:
		break;
	default:
		break;
	}



}
