#pragma once
#include "Ilha.h"
using namespace std;
class Refugio : public Ilha
{
	static int numTerr;
public:
	Refugio();
	tipoTerritorio getType()const;
};

