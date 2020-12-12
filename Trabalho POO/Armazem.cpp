#include "Armazem.h"
#include <string>
#include <sstream>
using namespace std;

Armazem::Armazem(int quantInicial, int max)
	: quantidadeAtual(quantInicial), quantidadeMax(max) {
}

int Armazem::getQuantidadeAtual() const {
	return quantidadeAtual;
}

int Armazem::getQuantidadeMax() const {
	return quantidadeMax;
}

string Armazem::info() const {
	ostringstream oss;
	oss << "quantidade : " << quantidadeAtual
		<< "; max: " << quantidadeMax << endl;
	return oss.str();
}


void Armazem::setQuantidadeAtual(int value ){
	if (value > quantidadeMax) {
		quantidadeAtual = quantidadeMax;
	}
	else {
		quantidadeAtual = value < 0 ? 0 : value;
	}
}

void Armazem::setQuantidadeMax(int max) {
	quantidadeMax = max;
}

void Armazem::add(int value) {
	int q = quantidadeAtual + value;
	setQuantidadeAtual(q);
}

void Armazem::rem(int value) {
	int q = quantidadeAtual - value;
	setQuantidadeAtual(q);
}