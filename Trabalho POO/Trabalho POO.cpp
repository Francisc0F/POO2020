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
#include "Imperio.h"
using namespace std;

int main()
{
	// const string testf = "territorios.txt";
	Mundo m = Mundo();
	Imperio I = Imperio();

	vector<string> menuValues;
	


	while (1) {
		menuOpt opt = Menu::verMenu(menuValues);
		if (opt == menuOpt::Terminar) {
			break;
		}
		if (opt != menuOpt::Invalido) {
			Menu::ExecutaComando(opt, menuValues, m, I);
		}
	}
	
}
