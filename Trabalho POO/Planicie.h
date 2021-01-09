#pragma once
#include <string>
#include "Continente.h"
using namespace std;
class Planicie : public Continente
{
	static int numTerr;

public:
	Planicie();
	Planicie(string nome, int resistencia, int nProdutos, int nOuro);


	Planicie* clone()const;

	tipoTerritorio getType()const;
};

