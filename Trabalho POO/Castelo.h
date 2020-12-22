#pragma once
#include <string>
#include "Continente.h"

using namespace std;
class Castelo : public Continente
{
	static int numTerr;

public:
	Castelo();

	tipoTerritorio getType()const;
};

