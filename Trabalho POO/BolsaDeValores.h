#pragma once
#include "Tecnologias.h"
class BolsaDeValores : public Tecnologias
{
public:
	BolsaDeValores();

	virtual string getDescricao() const;

	virtual tec getType() const;
};

