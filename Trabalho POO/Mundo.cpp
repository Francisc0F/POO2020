#include "Mundo.h"
#include "Territorio.h"
#include "Menu.h"
#include "Imperio.h"

using namespace std;

Mundo::Mundo() {

}
Mundo::~Mundo() {

	//todo delete territorios
}

vector<Territorio*> & Mundo::getTerritorios() {
	return territorios;
}

void Mundo::adicionarTerritorio(string nome, int resistencia, int nProdutos, int nOuro, int pontos) {
	
	territorios.push_back(new Territorio(nome, resistencia, nProdutos, pontos));

}

void Mundo::addNTerritorios(int n, string nome) {
	for ( int i = 0; i < n; i++)
	{
		territorios.push_back(new Territorio(nome));
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

		// remove inicial space
		 nome = nome.substr(1, nome.size());

		//cout << "\""<< nome <<"\"" << endl;
		if (iss) {
			adicionarTerritorio(nome, resistencia, nProdutos, nOuro, pontos);
		}
		else {
			cout << "error: iss leitura" << endl;
			return false;
		}
	}
	dados.close();

	return true;
}

bool Mundo::LerComandosFich(string nomef, Mundo & m, Imperio & I) {
	ifstream dados(nomef);
	if (!dados.is_open()) {
		cout << "error abrir ficheiro: " << nomef << endl;
		return false;
	}
	string line;
	string comando;

	// cria planicie 2

	while (!dados.eof()) {

		getline(dados, line);
		cout << line << endl;

		istringstream iss(line);
		vector<string> comand_tokens;


		if (line == "") {
			cout << "error leitura: " << nomef;
			return false;
		}

		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(comand_tokens));
		vector<string> values;
		values.clear();

		menuOpt opt =  Menu::ProcessaComando(values, comand_tokens);
		Menu::ExecutaComando(opt, values, m, I);

	}
	dados.close();

	return true;

}