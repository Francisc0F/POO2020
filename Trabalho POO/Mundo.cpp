#include "Mundo.h"
#include "Territorio.h"
#include "Menu.h"
#include "Imperio.h"

using namespace std;

Mundo::Mundo() {

}
Mundo::~Mundo() {
	for (int i = 0; i < territorios.size(); i++)
	{
		delete territorios[i];
	}
	territorios.clear();
}

vector<Territorio*> & Mundo::getTerritorios() {
	return territorios;
}

void Mundo::adicionarTerritorio(Territorio* t) {

	territorios.push_back(t);
}

//void Mundo::adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
//	
//	territorios.push_back(new Territorio(nome, resistencia, nProdutos, pontos));
//
//}

void Mundo::addNTerritorios(int n, tipoTerritorio t) {
	
	for ( int i = 0; i < n; i++)
	{
		territorios.push_back(Territorio::mapper(t));
	}

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
	if (territorios.size() == 0) {
		cout << "Nao ha territorios no Mundo." << endl;
		return;
	}
	for (ptr = territorios.begin(); ptr < territorios.end(); ptr++) {
		cout << (*ptr)->getAsString() << endl;
	}
}

//bool Mundo::LerFich(string nomef) {
//
//	ifstream dados(nomef);
//	if (!dados.is_open()) {
//		cout << "error: abrir ficheiro" << endl;
//		return false;
//	}
//	string line;
//
//	string nome;
//	int resistencia, nProdutos, nOuro, pontos;
//
//	// apanhar primeira linha 
//	getline(dados, line);
//
//	while (!dados.eof()) {
//
//		getline(dados, line);
//
//		istringstream iss(line);
//		iss >> resistencia >> nProdutos >> nOuro >> pontos;
//		getline(iss, nome);
//
//		// remove inicial space
//		 nome = nome.substr(1, nome.size());
//
//		//cout << "\""<< nome <<"\"" << endl;
//		if (iss) {
//			adicionarTerritorio(nome, resistencia, nProdutos, nOuro, pontos);
//		}
//		else {
//			cout << "error: iss leitura" << endl;
//			return false;
//		}
//	}
//	dados.close();
//
//	return true;
//}

//bool Mundo::LerComandosFich(string nomef, Mundo & m, Imperio & I,  vector<Tecnologias* > & tecnologias) {
//	ifstream dados(nomef);
//	if (!dados.is_open()) {
//		cout << "error abrir ficheiro: " << nomef << endl;
//		return false;
//	}
//	string line;
//	string comando;
//
//	// cria planicie 2
//
//	while (!dados.eof()) {
//
//		getline(dados, line);
//		cout << line << endl;
//
//		istringstream iss(line);
//		vector<string> comand_tokens;
//
//
//		if (line == "") {
//			cout << "error leitura: " << nomef;
//			return false;
//		}
//
//		copy(istream_iterator<string>(iss),
//			istream_iterator<string>(),
//			back_inserter(comand_tokens));
//		vector<string> values;
//		values.clear();
//
//		menuOpt opt =  Menu::ProcessaComando(values, faseTurno::Config,  comand_tokens);
//		Menu::ExecutaComando(opt, values, m, I, tecnologias);
//
//	}
//	dados.close();
//
//	return true;
//
//}