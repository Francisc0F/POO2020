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

Duna::Duna(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
	this->pontos = pontos;
}

tipoTerritorio Duna::getType()const {
	return tipoTerritorio::Duna;
}