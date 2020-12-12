#pragma once

#include <vector>
#include "Mundo.h"
using namespace std;

enum class menuOpt {
	CarregaComand = 0,
	CarregaFich,
	Cria,
	Conquista,
	Passa, 
	Lista, 
	Terminar,
	MaisProd,
	MaisOuro,
	MaisMilitar,
	Invalido
};
class Menu
{
public:
	Menu();
	// comandos
	menuOpt static verMenu(vector<string> & values, int turno);

	menuOpt static ProcessaComando(vector<string>& values, vector<string>& comand_tokens);

	void static ExecutaComando(menuOpt opt, vector<string> & menuValues, Mundo & m, Imperio & I, int * turno);

};

