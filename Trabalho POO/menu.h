#pragma once

#include <vector>
using namespace std;

enum class menuOpt {
	CarregaFich = 0,
	Cria = 1,
	Conquista = 2,
	Passa = 3,
	Lista = 4,
	Terminar
};
class Menu
{


public:
	Menu();
	// comandos
	menuOpt static verMenu(vector<string> & values);

};

