#include "Refugio.h"
#include <sstream>
#include <iostream>

int Refugio::numTerr = 1;

Refugio::Refugio() {
	ostringstream oss;
	oss << "Refugio" << numTerr;
	nome = oss.str();

	resistencia = 9;
	nProdutos = 0;
	nOuro = 1;
	numTerr++;
}
