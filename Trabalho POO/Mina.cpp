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

Mina::Mina(string nome, int resistencia, int nProdutos, int nOuro) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
}

tipoTerritorio Mina::getType()const {
	return tipoTerritorio::Mina;
}