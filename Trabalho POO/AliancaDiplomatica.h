#pragma once
#include "Eventos.h"
class AliancaDiplomatica: public Eventos
{
public:
	AliancaDiplomatica();

	tipoEvento getType()const;

	string getDescricao()const;
};

