#include "Pescaria.h"
#include <sstream>
#include <iostream>

int Pescaria::numTerr = 1;

Pescaria::Pescaria() {
	ostringstream oss;
	oss << "Pescaria" << numTerr;
	nome = oss.str();

	resistencia = 9;
	nProdutos = 2;
	nOuro = 0;
	numTerr++;
}
