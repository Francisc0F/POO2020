#pragma once
#include <string>
#include "Continente.h"
using namespace std;

Continente::Continente() {
	pontos = 1;
}


int Continente::getnProdutos() {
	return nProdutos;
}
int Continente::getnOuro() {
	return nOuro;
}