#include <sstream>
#include <iostream>
#include "Mina.h"


int Mina::numTerr = 1;
Mina::Mina() {
	ostringstream oss;
	nome = "Mina";
	if (numTerr > 0) {
		oss << nome << numTerr;
	}
	resistencia = 5;
	nProdutos = 0;
	nOuro = 1;
	numTerr++;
}