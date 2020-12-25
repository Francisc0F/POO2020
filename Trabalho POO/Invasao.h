#pragma once
#include <string>
#include "Eventos.h"

class Invasao : public Eventos
{

public:
	Invasao();
	tipoEvento getType()const;
	string getDescricao()const;
};

