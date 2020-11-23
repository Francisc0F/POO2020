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
	vector<Territorio* > territorios;


public:

	Mundo();

	bool adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos);

	int pesquisa(string nome);

	~Mundo();

};

