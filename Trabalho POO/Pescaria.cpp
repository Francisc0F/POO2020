#include <sstream>
#include <iostream>
#include "App.h"
#include "Pescaria.h"

int Pescaria::numTerr = 1;

Pescaria::Pescaria() {
	ostringstream oss;
	oss << "Pescaria" << numTerr;
	nome = oss.str();

	resistencia = 9;
	nProdutos = 2;
	nOuro = 0;
	numTerr++;
}

Pescaria* Pescaria::clone() const {
	return new Pescaria(*this);
}

Pescaria::Pescaria(string nome, int resistencia, int nProdutos, int nOuro) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
}

tipoTerritorio Pescaria::getType()const {
	return tipoTerritorio::Refugio;
}
