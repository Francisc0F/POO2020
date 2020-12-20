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
#include "Armazem.h"
using namespace std;

class Territorio;

class Imperio
{
	Armazem Produtos;
	Armazem Cofre;

	int forcaMilitar, capacidadeForcaMilitar;

	static int turnos;

	vector<Territorio *> conquistados;

public:

	Imperio();

	Imperio(Territorio*, Armazem& Produtos, Armazem& Ouro);

	Armazem& getProdutos();

	Armazem& getCofre();

	void conquistaTerritorio(Territorio * t);

	void listaConquistados();

	int pesquisaTerritorio(string nome)const;

	void mostraRecursos()const;

	bool maisOuro();
	
	bool maisProdutos();

	void RecolherRecursos();

	~Imperio();
};

