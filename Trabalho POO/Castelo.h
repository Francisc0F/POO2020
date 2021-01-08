#pragma once
#include <string>
#include "Continente.h"

using namespace std;
class Castelo : public Continente
{
	static int numTerr;

public:
	Castelo();
	Castelo(string nome, int resistencia, int nProdutos , int nOuro , int pontos);

	tipoTerritorio getType()const;

	Castelo* clone()const;
};

