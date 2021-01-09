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

	//bool podeConquistarIlhas;

	//bool armazensAumentados;

	//bool defesasTerritoriais;

	//bool trocasComerciais;

	vector<Territorio *> conquistados;

	vector<Tecnologias* > tecnologias;


public:

	Imperio();

	Armazem& getProdutos();

	Armazem& getCofre();

	string getForcaMilitar()const;

	void setCapacidadeForcaMilitar(int v);

	void setForcaMilitar(int v);

	void addForcaMilitar(int v);

	bool conquistaTerritorio(Territorio * t);

	bool forceConquistaTerritorio(Territorio * t);

	Territorio* getUltimoConquistado();

	void RemoveUltimoConquistado();

	vector<Tecnologias*>& getTecs();

	void addT(Territorio* t);

	string listaConquistados();

	int pesquisaTerritorio(string nome)const;

	string mostraRecursos()const;

	string verTecnologias()const;

	string getAsString();

	bool maisOuro();
	
	bool maisProdutos();

	bool maisMilitar();
	
	bool comprarTec(tec t, Tecnologias* pt);

	void addTec(Tecnologias* pt);

	bool temTec(tec n);

	void RecolherRecursos();

	//bool getTemDefesasTerritoriais();

	//bool getTemtrocasComerciais();

	vector<Territorio*>& getConquistados();
	
	bool forceAdquirirTec(Tecnologias* pt);

	~Imperio();
};

ostream& operator<<(ostream& os, Imperio& i);

ostream& operator<<(ostream& os, Imperio* i);
