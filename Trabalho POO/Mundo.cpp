#include "Mundo.h"
#include "Territorio.h"



bool Mundo::adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	
	if (pesquisa(nome) == -1) {
		territorios.push_back(new Territorio(nome, resistencia, nProdutos, pontos));
		return true;
	}
		
	return false;
}


int Mundo::pesquisa(string nome) {
	vector<Territorio* >::iterator ptr;

	for (unsigned int i = 0; i < territorios.size(); i++) {
		if (territorios[i]->getNome() == nome) {
			return i;
		}
	}
	return -1;
}