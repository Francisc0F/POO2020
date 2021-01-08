#include <sstream>
#include <iostream>
#include "Montanha.h"


int Montanha::numTerr = 1;
Montanha::Montanha() {
	ostringstream oss;
	oss << "Montanha" << numTerr;
	nome = oss.str();
	resistencia = 6;
	nProdutos = 0;
	nOuro = 0;
	numTerr++;

	turnosAposConquista = 0;
}

Montanha* Montanha::clone() const {
	return new Montanha(*this);
}


Montanha::Montanha(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
	this->pontos = pontos;
}

void Montanha::addTurno() {
	turnosAposConquista++;
}

tipoTerritorio Montanha::getType()const {
	return tipoTerritorio::Montanha;
}