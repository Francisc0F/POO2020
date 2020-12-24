#include "Tecnologias.h"
//Tecnologias::Tecnologias() {
//
//}


tec Tecnologias::tecValida(string n) {
	if (n == "missil") {
		return tec::MisseisTeleguiados;
	}
	else if (n == "drones") {
		return tec::DronesMilitares;
	}
	else if (n == "defesas") {
		return tec::DefesasTerritoriais;
	}
	else if (n == "bolsa") {
		return tec::BolsaDeValores;
	}
	else if (n == "banco") {
		return tec::BancoCentral;
	}
	return tec::Invalida;
}

int Tecnologias::getCusto()const {
	return custo;
}
string Tecnologias::getCustoAsString()const {
		ostringstream oss;
		oss << "custo :" << custo << endl;
		return oss.str();
}