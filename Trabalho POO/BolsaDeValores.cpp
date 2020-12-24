#include "BolsaDeValores.h"
BolsaDeValores::BolsaDeValores() {
	custo = 2;
}
string BolsaDeValores::getDescricao()const {
	ostringstream oss;
	oss << "Bolsa de Valores: Sistema comercial que torna possíveis as trocas entre produtos e ouro.";
	return oss.str();
}

tec BolsaDeValores::getType()const {
	return tec::BolsaDeValores;
}