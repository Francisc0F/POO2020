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

Castelo::Castelo(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
	this->pontos = pontos;
}

tipoTerritorio Castelo::getType()const {
	return tipoTerritorio::Castelo;
}