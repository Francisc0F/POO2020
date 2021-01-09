#pragma once
#include <string>
#include "Continente.h"
using namespace std;

class Duna : public Continente
{
	static int numTerr;

public:
	Duna();
	
	Duna(string nome , int resistencia, int nProdutos , int nOuro);

	Duna* clone()const;

	tipoTerritorio getType()const;
};

