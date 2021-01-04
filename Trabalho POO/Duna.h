#pragma once
#include <string>
#include "Continente.h"
using namespace std;

class Duna : public Continente
{
	static int numTerr;

public:
	Duna();
	
	Duna(string nome , int resistencia, int nProdutos , int nOuro , int pontos );

	// get
	int getnProdutos();
	int getnOuro();

	tipoTerritorio getType()const;
};

