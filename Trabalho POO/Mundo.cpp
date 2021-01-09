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
#include "App.h"
#include "TerritorioInicial.h"

using namespace std;

Mundo::Mundo() {
	if (App::debugMode) {
		cout << "Construiu MUNDO" << endl;
	}
	
}

Mundo::Mundo(const Mundo& other) {
	*this = other;
}
Mundo::~Mundo() {
	if (App::debugMode) {
		cout << "~Mundo() Destruiu MUNDO e TERRITORIOS" << endl;
	}

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
	oss << "\t\t Mundo" << endl;
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

