#include <sstream>
#include <iostream>
#include "Planicie.h"


int Planicie::numTerr = 1;
Planicie::Planicie() {
	ostringstream oss;
	if (numTerr > 0) {
		oss << nome << numTerr;
	}
	resistencia = 5;
	nProdutos = 1;
	nOuro = 1;
	numTerr++;
}