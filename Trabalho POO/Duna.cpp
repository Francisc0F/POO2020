#include <sstream>
#include <iostream>
#include "Duna.h"


 int Duna::numTerr = 1;
Duna::Duna() {
	ostringstream oss;
	nome = "Duna";
	if (numTerr > 0) {
		oss << nome  << numTerr;
	}
	resistencia = 4;
	nProdutos = 1;
	nOuro = 0;
	numTerr++;
}