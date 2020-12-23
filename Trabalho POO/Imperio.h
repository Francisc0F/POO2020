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
#include "Tecnologias.h"
using namespace std;

class Territorio;

class Imperio
{
	Armazem Produtos;
	Armazem Cofre;

	int forcaMilitar, capacidadeForcaMilitar;

	vector<Territorio *> conquistados;

	vector<Tecnologias* > tecnologias;


public:

	Imperio();


	Imperio(Territorio*, Armazem& Produtos, Armazem& Ouro);

	Armazem& getProdutos();

	Armazem& getCofre();

	string getForcaMilitar()const;

	void conquistaTerritorio(Territorio * t);

	void listaConquistados();

	int pesquisaTerritorio(string nome)const;

	void mostraRecursos()const;

	void verTecnologias()const;

	bool maisOuro();
	
	bool maisProdutos();

	bool maisMilitar();
	
	bool adquirirTec(tec t, Tecnologias* pt);

	bool temTec(string n);

	void RecolherRecursos();

	~Imperio();
};

