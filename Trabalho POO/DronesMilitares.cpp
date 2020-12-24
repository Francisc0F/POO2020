#include "DronesMilitares.h"


DronesMilitares::DronesMilitares() {
	custo = 3;
}


string DronesMilitares::getDescricao()const {
	ostringstream oss;
	oss << "Drones Militares: Ao ser adquirida, esta tecnologia faz passar o limite máximo da força militar para 5";
	return oss.str();
}


tec DronesMilitares::getType()const {
	return tec::DronesMilitares;
}