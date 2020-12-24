#include "DefesasTerritoriais.h"
DefesasTerritoriais::DefesasTerritoriais() {
	custo = 4;
}

string DefesasTerritoriais::getDescricao()const {
	ostringstream oss;
	oss << "Defesas Territoriais: E um equipamento especial de defesa que acrescenta 1 unidade à resistência do território invadido durante um evento de invasão";
	return oss.str();
}


tec DefesasTerritoriais::getType()const {
	return tec::DefesasTerritoriais;
}