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

Pescaria::Pescaria(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
	this->pontos = pontos;
}

tipoTerritorio Pescaria::getType()const {
	return tipoTerritorio::Refugio;
}
