#pragma once
#include <string>
#include "Continente.h"
using namespace std;

class Mina : public Continente
{
	static int numTerr;

public:
	Mina();

	Mina* clone() const;

	tipoTerritorio getType()const;
};

