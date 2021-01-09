#pragma once
#include <string>
#include "Continente.h"
using namespace std;

class Fortaleza : public Continente
{
	static int numTerr;

public:
	Fortaleza();
	Fortaleza(string nome, int resistencia, int nProdutos, int nOuro);

	Fortaleza* clone()const;
	tipoTerritorio getType()const;
};

