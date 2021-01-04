#pragma once
#include "Ilha.h"
using namespace std;
class Pescaria : public Ilha
{
	static int numTerr;
public:

	Pescaria();
	Pescaria(string nome, int resistencia, int nProdutos, int nOuro, int pontos);

	tipoTerritorio getType()const;
};

