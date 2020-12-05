#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include "Imperio.h"

using namespace std;

class Territorio;

class Mundo
{
	vector<Territorio * > territorios;

public:

	Mundo();

	void listaTerritorios();

	void adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos);
	
	void addNTerritorios(int n, string nome);

	int pesquisaTerritorio(string nome);

	bool LerFich(string nomef);
	
	bool LerComandosFich(string nomef, Mundo & m, Imperio & I);

	//getters
	vector<Territorio*>& getTerritorios();

	~Mundo();

};

