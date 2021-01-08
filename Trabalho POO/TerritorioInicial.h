#pragma once
#include "Territorio.h"
class TerritorioInicial : public Territorio
{
public:
	TerritorioInicial();
	TerritorioInicial(string nome, int resistencia, int nProdutos, int nOuro, int pontos);

	tipoTerritorio getType()const;

	TerritorioInicial* clone()const;

	categoria getCategoria()const;
};

