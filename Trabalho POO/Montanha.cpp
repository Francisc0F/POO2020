#include <sstream>
#include <iostream>
#include "Montanha.h"


int Montanha::numTerr = 1;
Montanha::Montanha() {
	ostringstream oss;
	oss << "Montanha" << numTerr;
	nome = oss.str();
	resistencia = 6;
	nProdutos = 0;
	nOuro = 0;
	numTerr++;
}