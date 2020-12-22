#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Territorio.h"
#include "Planicie.h"
#include "Montanha.h"
#include "Fortaleza.h"
#include "Duna.h"
#include "Mina.h"
#include "Castelo.h"
#include "Refugio.h"
#include "Pescaria.h"


//getters
string Territorio::getAsString() const {
	ostringstream oss;
	oss << "nome: " << nome
		//<< "; resistencia: " << resistencia
		<< "; nProdutos: " << nProdutos 
		<< "; nOuro: " << nOuro <<
		"; pontos: " << pontos;
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

int Territorio::getResistencia()const {
	return resistencia;
}



//setters

void Territorio::setResistencia(int n) {
	resistencia = n;
}

void Territorio::setnProdutos(int n) {
	nProdutos = n;
}

void Territorio::setnOuro(int  n) {
	nOuro = n;
}

void Territorio::setpontos(int  n) {
	pontos = n;
}


Territorio* Territorio::mapper(tipoTerritorio t) {
	switch (t)
	{
	case tipoTerritorio::Planicie: {
		return new Planicie();
		break;
	}

	case tipoTerritorio::Montanha: {
		return new Montanha();
		break;
	}
	case tipoTerritorio::Fortaleza: {
		return new Fortaleza();
		break;
	}
	case tipoTerritorio::Mina: {
		return new Mina();
		break;
	}
	case tipoTerritorio::Duna: {
		return new Duna();
		break;
	}
	case tipoTerritorio::Castelo: {
		return new Castelo();
		break;
	}
	case tipoTerritorio::Refugio: {
		return new Refugio();
		break;
	}
	case tipoTerritorio::Pescaria: {
		return new Pescaria();
		break;
	}
	default:
		break;
	}
}


tipoTerritorio Territorio::validaTipoTerritorio(string tipo) {
	if (tipo == "Planicie") {
		return tipoTerritorio::Planicie;
	}
	else if (tipo == "Montanha") {
		return tipoTerritorio::Montanha;
	}
	else if (tipo == "Fortaleza") {
		return tipoTerritorio::Fortaleza;
	}
	else if (tipo == "Mina") {
		return tipoTerritorio::Mina;
	}
	else if (tipo == "Duna") {
		return tipoTerritorio::Duna;
	}
	else if (tipo == "Castelo") {
		return tipoTerritorio::Castelo;
	}
	else if (tipo == "Refugio") {
		return tipoTerritorio::Refugio;
	}
	else if (tipo == "Pescaria") {
		return tipoTerritorio::Pescaria;
	}
	else {
		return tipoTerritorio::Invalido;
	}
}