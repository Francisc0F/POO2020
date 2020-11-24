#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Territorio.h"


Territorio::Territorio() {
}

Territorio::Territorio(string nome = "Sem nome", int resistencia = 0, int nProdutos = 0, int pontos = 0 )
	: nome(nome), resistencia(resistencia), nProdutos(nProdutos), pontos(pontos) {
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





