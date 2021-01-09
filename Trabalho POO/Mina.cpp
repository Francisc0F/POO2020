#include <sstream>
#include <iostream>
#include "Mina.h"
#include "App.h"


int Mina::numTerr = 1;
Mina::Mina() {
	ostringstream oss;
	oss << "Mina" << numTerr;
	nome = oss.str();
	
	resistencia = 5;
	nProdutos = 0;
	nOuro = 1;
	numTerr++;
}

Mina* Mina::clone() const {
	return new Mina(*this);
}


tipoTerritorio Mina::getType()const {
	return tipoTerritorio::Mina;
}