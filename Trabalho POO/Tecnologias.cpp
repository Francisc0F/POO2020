#include "Tecnologias.h"
//Tecnologias::Tecnologias() {
//
//}

tec Tecnologias::tecValida(string n) {
	if (n == "MisseisTeleguiados") {
		return tec::MisseisTeleguiados;
	}
	else if (n == "DronesMilitares") {
		return tec::DronesMilitares;
	}
	else if (n == "DefesasTerritoriais") {
		return tec::DefesasTerritoriais;
	}
	else if (n == "BolsaDeValores") {
		return tec::BolsaDeValores;
	}
	else if (n == "BancoCentral") {
		return tec::BancoCentral;
	}
	return tec::Invalida;
}

int Tecnologias::getCusto()const {
	return custo;
}
void Tecnologias::mostraTec()const {
	
}