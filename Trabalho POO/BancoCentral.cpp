#include "BancoCentral.h"
BancoCentral::BancoCentral() {
	custo = 2;
}

string BancoCentral::getDescricao()const {
	ostringstream oss;
	oss << "Banco Central: Ao ser adquirida, esta tecnologia permite aumentar em duas unidades a capacidade de armazenamento do armaz�m e do cofre do imp�rio";
	return oss.str();
}
tec BancoCentral::getType()const {
	return tec::BancoCentral;
}