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

using namespace std;

class Territorio;

class Mundo
{
	vector<Territorio * > territorios;

public:

	Mundo();

	void listaTerritorios();

	void adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos);
	
	void addNTerritorios(int n);

	int pesquisaTerritorio(string nome);

	bool LerFich(string nomef);

	//getters
	vector<Territorio*>& getTerritorios();

	~Mundo();

};

