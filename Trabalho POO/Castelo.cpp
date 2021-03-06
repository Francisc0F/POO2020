#include <sstream>
#include <iostream>
#include "Castelo.h"

int Castelo::numTerr = 1;
Castelo::Castelo() {
	ostringstream oss;
	oss << "Castelo" << numTerr;
	nome = oss.str();

	resistencia = 7;
	nProdutos = 1;
	nOuro = 1;
	numTerr++;
}

Castelo* Castelo::clone() const {
	return new Castelo(*this);
}


tipoTerritorio Castelo::getType()const {
	return tipoTerritorio::Castelo;
}