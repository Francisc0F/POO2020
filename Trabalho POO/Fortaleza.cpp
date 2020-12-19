#include <sstream>
#include <iostream>
#include "Fortaleza.h"


int Fortaleza::numTerr = 1;
Fortaleza::Fortaleza() {
	ostringstream oss;
	if (numTerr > 0) {
		oss << nome << numTerr;
	}
	resistencia = 8;
	nProdutos = 0;
	nOuro = 0;
	numTerr++;
}