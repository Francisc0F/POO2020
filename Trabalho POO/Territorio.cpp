#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Territorio.h"



int Territorio::numTerr = 0;


Territorio::Territorio(string nomeT, int resistencia , int nProdutos, int ouro , int pontos)
	:resistencia(resistencia), nProdutos(nProdutos), nOuro(ouro), pontos(pontos) {
	ostringstream oss;
	if (numTerr > 0) {
		oss << nomeT << numTerr;
	}
	else {
		oss << nomeT;
	}
	nome = oss.str();
	numTerr++;
}


//getters
string Territorio::getAsString() const {
	ostringstream oss;
	oss << "nome: " << nome
		<< "; resistencia: " << resistencia
		<< "; nProdutos: " << nProdutos << endl;
	return oss.str();
}


string Territorio::getNome()const {
	return nome;
}


int Territorio::getnProdutos()const {
	return nProdutos;
}


int Territorio::getnOuro()const {
	return nOuro;
}

int Territorio::getpontos()const {
	return pontos;
}



//setters
void Territorio::setnProdutos(int n) {
	nProdutos = n;
}

void Territorio::setnOuro(int  n) {
	nOuro = n;
}

void Territorio::setpontos(int  n) {
	pontos = n;
}





