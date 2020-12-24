#pragma once
#include "Territorio.h"
class TerritorioInicial : public Territorio
{
public:
	TerritorioInicial();

	tipoTerritorio getType()const;

	categoria getCategoria()const;
};

