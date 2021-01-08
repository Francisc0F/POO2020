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
#include "Territorio.h"

using namespace std;

class Territorio;

class Mundo
{
	vector<Territorio * > territorios;

public:

	Mundo();

	Mundo(const Mundo& other);

	string listaTerritorios();

	void adicionarTerritorio(Territorio* t);

	//void adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos);
	
	void addNTerritorios(int n, tipoTerritorio nome);

	int pesquisaTerritorio(string nome);

	bool LerFich(string nomef);
	

//	bool LerComandosFich(string nomef, Mundo & m, Imperio & I, vector<Tecnologias* >& tecnologias);

	//getters
	vector<Territorio*>& getTerritorios();

	Mundo* clone(const Mundo & other);
	
	Mundo& operator=(const Mundo& other);

	~Mundo();

};


ostream& operator<<(ostream& os, Mundo& i);

ostream& operator<<(ostream& os, Mundo* i);
