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
#include "Eventos.h"
using namespace std;

class Territorio;

class Imperio
{
	Armazem Produtos;
	Armazem Cofre;

	int forcaMilitar, capacidadeForcaMilitar;

	bool podeConquistarIlhas;

	bool armazensAumentados;

	bool defesasTerritoriais;

	bool trocasComerciais;

	vector<Territorio *> conquistados;

	vector<Tecnologias* > tecnologias;

	vector<Eventos* > eventosGerados;


public:

	Imperio();

	Imperio(Territorio*, Armazem& Produtos, Armazem& Ouro);

	Armazem& getProdutos();

	Armazem& getCofre();

	string getForcaMilitar()const;

	void setCapacidadeForcaMilitar(int v);

	bool conquistaTerritorio(Territorio * t);

	bool forceConquistaTerritorio(Territorio * t);

	Territorio* getUltimoConquistado();

	void listaConquistados();

	int pesquisaTerritorio(string nome)const;

	void mostraRecursos()const;

	void verTecnologias()const;

	bool maisOuro();
	
	bool maisProdutos();

	bool maisMilitar();
	
	bool comprarTec(tec t, Tecnologias* pt);

	void addTec(Tecnologias* pt);

	bool temTec(tec n);

	void RecolherRecursos();

	bool getTemtrocasComerciais();
	
	bool forceAdquirirTec(Tecnologias* pt);

	~Imperio();
};

