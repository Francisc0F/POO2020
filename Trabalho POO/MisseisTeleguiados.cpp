#include "MisseisTeleguiados.h"
MisseisTeleguiados::MisseisTeleguiados() {
	custo = 4;
}


string MisseisTeleguiados::getDescricao()const {
	ostringstream oss;
	oss << "Misseis Teleguiados: Esta tecnologia � necess�ria para conquistar ilhas.";
	return oss.str();
}


tec MisseisTeleguiados::getType()const {
	return tec::MisseisTeleguiados;
}