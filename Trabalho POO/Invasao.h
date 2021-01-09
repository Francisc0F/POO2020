#pragma once
#include <string>
#include "Eventos.h"

class Invasao : public Eventos
{

public:
	tipoEvento getType()const;
	string getDescricao()const;
};

