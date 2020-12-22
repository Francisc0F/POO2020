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

	tipoTerritorio getType()const;

	void addTurno();
};

