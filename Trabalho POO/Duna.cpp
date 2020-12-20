#include <sstream>
#include <iostream>
#include "Duna.h"

 int Duna::numTerr = 1;

Duna::Duna() {
	ostringstream oss;
	oss << "Duna"  << numTerr;
	nome = oss.str();

	resistencia = 4;
	nProdutos = 1;
	nOuro = 0;
	numTerr++;
}