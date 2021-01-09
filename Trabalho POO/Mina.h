#pragma once
#include <string>
#include "Continente.h"
using namespace std;

class Mina : public Continente
{
	static int numTerr;

public:
	Mina();
	Mina(string nome, int resistencia, int nProdutos, int nOuro);

	Mina* clone() const;

	tipoTerritorio getType()const;
};

