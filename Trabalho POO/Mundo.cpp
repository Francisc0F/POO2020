#include "Mundo.h"
#include "Territorio.h"
#include "Menu.h"
#include "Imperio.h"
#include "Duna.h"
#include "Castelo.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Montanha.h"
#include "Pescaria.h"
#include "Planicie.h"
#include "Refugio.h"
#include "TerritorioInicial.h"

using namespace std;

Mundo::Mundo() {
	cout << "Construiu MUNDO" << endl;
}

Mundo::Mundo(const Mundo& other) {
	*this = other;
}
Mundo::~Mundo() {
	cout << "~Mundo Destruir Mundo e territorios" << endl;
	for (int i = 0; i < territorios.size(); i++)
	{
		delete territorios[i];
	}
	territorios.clear();
}

Mundo& Mundo::operator=(const Mundo& other) {

	if (this != &other) {
		for (auto t : territorios) {
			delete t;
		}
		territorios.clear();
	}
	for (auto t : other.territorios) {
		territorios.push_back(t->clone());
	}
	return *this;
}


vector<Territorio*> & Mundo::getTerritorios() {
	return territorios;
}

void Mundo::adicionarTerritorio(Territorio* t) {

	territorios.push_back(t);
}

Mundo* clone(Mundo& ref) {
	return new Mundo();
}

ostream& operator<< (ostream& os, Mundo& i) {
	return os << i.listaTerritorios();
}

ostream& operator<< (ostream& os, Mundo* i) {
	return os << i->listaTerritorios();
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

string Mundo::listaTerritorios() {
	ostringstream oss;
	vector<Territorio* >::iterator ptr;
	if (territorios.size() == 0) {
		oss << "Nao ha territorios no Mundo." << endl;
		return oss.str();
	}
	for (ptr = territorios.begin(); ptr < territorios.end(); ptr++) {
		oss << (*ptr)->getAsString() << endl;
	}
	return oss.str();
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