#pragma once
#include "Ilha.h"
using namespace std;
class Pescaria : public Ilha
{
	static int numTerr;
public:

	Pescaria();

	tipoTerritorio getType()const;

	Pescaria* clone()const;

};

