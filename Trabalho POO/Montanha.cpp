#include <sstream>
#include <iostream>
#include "Montanha.h"


int Montanha::numTerr = 1;
Montanha::Montanha() {
	ostringstream oss;
	nome = "Montanha";
	if (numTerr > 0) {
		oss << nome << numTerr;
	}
	resistencia = 6;
	nProdutos = 0;
	nOuro = 0;
	numTerr++;
}