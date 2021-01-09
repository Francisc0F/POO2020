#include <sstream>
#include <iostream>
#include "Fortaleza.h"


int Fortaleza::numTerr = 1;
Fortaleza::Fortaleza() {
	ostringstream oss;
	oss << "Fortaleza" << numTerr;
	nome = oss.str();

	resistencia = 8;
	nProdutos = 0;
	nOuro = 0;
	numTerr++;
}

Fortaleza* Fortaleza::clone() const {
	return new Fortaleza(*this);
}

tipoTerritorio Fortaleza::getType()const {
	return tipoTerritorio::Fortaleza;
}