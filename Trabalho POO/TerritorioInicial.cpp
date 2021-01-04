#include "TerritorioInicial.h"

TerritorioInicial::TerritorioInicial() {
	nome = "Pais";
	resistencia = 9;
	nProdutos = 1;
	nOuro = 1;
	pontos = 0;
}

TerritorioInicial::TerritorioInicial(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	this->nome = nome;
	this->resistencia = resistencia;
	this->nProdutos = nProdutos;
	this->nOuro = nOuro;
	this->pontos = pontos;
}

tipoTerritorio TerritorioInicial::getType()const {
	return tipoTerritorio::Inicial;
}

categoria TerritorioInicial::getCategoria()const {
	return categoria::Inicial;
}