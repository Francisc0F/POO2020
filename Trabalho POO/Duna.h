#pragma once
#include <string>
#include "Continente.h"
using namespace std;

class Duna : public Continente
{
	static int numTerr;

public:
	Duna();


	// get
	int getnProdutos();
	int getnOuro();

	tipoTerritorio getType()const;
};

