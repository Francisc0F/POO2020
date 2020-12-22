#pragma once
#include "Ilha.h"
using namespace std;
class Pescaria : public Ilha
{
	static int numTerr;
public:

	Pescaria();

	int getnProdutos();

	tipoTerritorio getType()const;
};

