#include "Mundo.h"
#include "Territorio.h"



bool Mundo::adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	
	//todo check exists
	territorios.push_back(new Territorio(nome, resistencia, nProdutos, pontos));
	
	return true;
}


int Mundo::pesquisa(string nome) {
	//todo
}