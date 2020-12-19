#include <sstream>
#include <iostream>
#include "Castelo.h"

int Castelo::numTerr = 1;
Castelo::Castelo() {
	ostringstream oss;
	if (numTerr > 0) {
		oss << nome << numTerr;
	}
	resistencia = 7;
	nProdutos = 1;
	nOuro = 1;
	numTerr++;
}