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

tipoTerritorio Mina::getType()const {
	return tipoTerritorio::Mina;
}