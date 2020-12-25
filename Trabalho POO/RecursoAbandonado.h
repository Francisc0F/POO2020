#pragma once
#include "Eventos.h"
class RecursoAbandonado : public Eventos
{
public:
	RecursoAbandonado();

	tipoEvento getType()const;

	string getDescricao()const;
};

