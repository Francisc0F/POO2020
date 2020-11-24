#pragma once

#include <vector>
using namespace std;

enum class menuOpt {
	CarregaFich = 0,
	Cria = 1,
	North = 33,
	South = 44
};
class Menu
{


public:
	Menu();
	// comandos
	menuOpt static verMenu(vector<string> & values);

};

