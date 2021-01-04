#pragma once
#include <string>
#include "Continente.h"
using namespace std;
class Montanha : public Continente
{

	static int numTerr;

	int turnosAposConquista;

public:
	Montanha();

	Montanha(string nome, int resistencia, int nProdutos, int nOuro, int pontos);

	tipoTerritorio getType()const;

	void addTurno();
};

