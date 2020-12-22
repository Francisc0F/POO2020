#include "TerritorioInicial.h"

TerritorioInicial::TerritorioInicial() {
	nome = "Pais";
	resistencia = 9;
	nProdutos = 1;
	nOuro = 1;
	pontos = 0;
}

tipoTerritorio TerritorioInicial::getType()const {
	return tipoTerritorio::Inicial;
}