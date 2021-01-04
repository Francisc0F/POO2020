#pragma once
#include <string>
#include "Continente.h"

using namespace std;
class Castelo : public Continente
{
	static int numTerr;

public:
	Castelo();
	Castelo(string nome = "Sem nome", int resistencia = 0, int nProdutos = 0, int nOuro = 0, int pontos = 0);

	tipoTerritorio getType()const;
};

