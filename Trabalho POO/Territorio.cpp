#include "Territorio.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

Territorio::Territorio() {
}

Territorio::Territorio(string nome, int resistencia, int nProdutos, int pontos)
	: nome("Sem nome"), resistencia(0), nProdutos(0), pontos(0) {
}


//getters
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


string Territorio::getAsString() const {
	ostringstream oss;
	oss << " nome: " << nome
		<< "; resistencia: " << resistencia
		<< "; nProdutos: " << nProdutos << endl;
	return oss.str();
}

bool Territorio::LerFich(string nomef) {

	ifstream dados(nomef);
	string line;

	string nome, s;
	int resistencia, nProdutos, nOuro, pontos;
	// apanhar primeira linha 
	getline(dados, line);

	while (!dados.eof()) {

		getline(dados, line);

		istringstream iss(s);
		iss >> resistencia >> nProdutos >> nOuro;
		getline(iss, nome);

		if (iss) {

		}
	}
	dados.close();

	return true;
}


