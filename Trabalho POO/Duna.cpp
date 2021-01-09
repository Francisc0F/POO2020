#include <sstream>
#include <iostream>
#include "Duna.h"
#include "App.h"

int Duna::numTerr = 1;

Duna::Duna() {
	ostringstream oss;
	oss << "Duna" << numTerr;
	nome = oss.str();
	resistencia = 4;
	nProdutos = 1;
	nOuro = 0;
	numTerr++;
}


Duna* Duna::clone() const {
	return new Duna(*this);
}

tipoTerritorio Duna::getType()const {
	return tipoTerritorio::Duna;
}