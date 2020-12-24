#include "DefesasTerritoriais.h"
DefesasTerritoriais::DefesasTerritoriais() {
	custo = 4;
}

string DefesasTerritoriais::getDescricao()const {
	ostringstream oss;
	oss << "Defesas Territoriais: E um equipamento especial de defesa que acrescenta 1 unidade � resist�ncia do territ�rio invadido durante um evento de invas�o";
	return oss.str();
}


tec DefesasTerritoriais::getType()const {
	return tec::DefesasTerritoriais;
}