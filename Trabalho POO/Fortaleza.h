#pragma once
#include <string>
#include "Continente.h"
using namespace std;

class Fortaleza : public Continente
{
	static int numTerr;

public:
	Fortaleza();
	int getnProdutos()const;
	int getnOuro()const;


	tipoTerritorio getType()const;
};

