#include "Mundo.h"
#include "Territorio.h"

Mundo::Mundo() {

}
Mundo::~Mundo() {

}

bool Mundo::adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	
	if (pesquisaTerritorio(nome) == -1) {
		territorios.push_back(new Territorio(nome, resistencia, nProdutos, pontos));
		return true;
	}
		
	return false;
}


int Mundo::pesquisaTerritorio(string nome) {

	for (unsigned int i = 0; i < territorios.size(); i++) {
		if (territorios[i]->getNome() == nome) {
			return i;
		}
	}
	return -1;
}
void Mundo::listaTerritorios() {

	vector<Territorio* >::iterator ptr;
	for (ptr = territorios.begin(); ptr < territorios.end(); ptr++) {
		cout << (*ptr)->getAsString() << endl;
	}
}
bool Mundo::LerFich(string nomef) {

	ifstream dados(nomef);
	if (!dados.is_open()) {
		cout << "error: abrir ficheiro" << endl;
		return false;
	}
	string line;

	string nome;
	int resistencia, nProdutos, nOuro, pontos;

	// apanhar primeira linha 
	getline(dados, line);

	while (!dados.eof()) {

		getline(dados, line);

		istringstream iss(line);
		iss >> resistencia >> nProdutos >> nOuro >> pontos;
		getline(iss, nome);

		if (iss) {
			if (adicionarTerritorio(nome, resistencia, nProdutos, nOuro, pontos) == false) {
				cout << "error: adicionarTerritorio" << endl;
				return false;
			}
		}
		else {
			cout << "error: iss leitura" << endl;
			return false;
		}
	}
	dados.close();

	return true;
}