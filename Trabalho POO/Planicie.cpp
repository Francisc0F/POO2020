#include <sstream>
#include <iostream>
#include "Planicie.h"
#include "App.h"


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

Planicie* Planicie::clone() const {
	return new Planicie(*this);
}

Planicie::Planicie(string nome, int resistencia, int nProdutos, int nOuro) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
}



tipoTerritorio Planicie::getType()const {
	return tipoTerritorio::Refugio;
}