#include <sstream>
#include <iostream>
#include "Planicie.h"


int Planicie::numTerr = 1;
Planicie::Planicie() {
	ostringstream oss;
	oss << "Planicie" << numTerr;
	nome = oss.str();

	resistencia = 5;
	nProdutos = 1;
	nOuro = 1;
	numTerr++;
}