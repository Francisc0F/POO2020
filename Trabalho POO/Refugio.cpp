#include <sstream>
#include <iostream>
#include "Refugio.h"
#include "App.h"


int Refugio::numTerr = 1;

Refugio::Refugio() {
	ostringstream oss;
	oss << "Refugio" << numTerr;
	nome = oss.str();

	resistencia = 9;
	nProdutos = 0;
	nOuro = 1;
	numTerr++;

}

Refugio::Refugio(string nome, int resistencia, int nProdutos, int nOuro) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
}



Refugio* Refugio::clone() const {
	return new Refugio(*this);
}




tipoTerritorio Refugio::getType()const {
	return tipoTerritorio::Refugio;
}