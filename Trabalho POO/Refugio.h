#pragma once
#include "Ilha.h"
using namespace std;
class Refugio : public Ilha
{
	static int numTerr;
public:
	Refugio();

	Refugio(string nome, int resistencia, int nProdutos, int nOuro, int pontos);

	tipoTerritorio getType()const;
};

