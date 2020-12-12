#include "Imperio.h"
#include "Territorio.h"

using namespace std;

int Imperio::turnos = 1;

Imperio::Imperio( Territorio * inicial, Armazem & Produtos, Armazem & Ouro)
: Produtos(Produtos), Cofre(Ouro){
	conquistados.push_back(inicial);
}

void Imperio::mostraRecursos()const {
	cout << "\t\t Recursos Materiais" << endl;
	cout << "Produtos " << endl;
	cout << Produtos.info();
	cout << "Cofre " << endl;
	cout << Cofre.info();
}



Armazem& Imperio::getProdutos(){
	return Produtos;
}

Armazem& Imperio::getCofre() {
	return Cofre;
}

void Imperio::listaConquistados()  {
	vector<Territorio* >::iterator ptr;
	ptr = conquistados.begin();
	if (conquistados.empty()) {
		cout << "Ainda nao foram conquistados Territorios." << endl;
		return;
	}
	for (ptr = conquistados.begin(); ptr < conquistados.end(); ptr++) {
		cout << (*ptr)->getAsString() << endl;
	}
}

int Imperio::pesquisaTerritorio(string nome)const {

	for (unsigned int i = 0; i < conquistados.size(); i++) {
		if (conquistados[i]->getNome() == nome) {
			return i;
		}
	}
	return -1;
}

void Imperio::conquistaTerritorio(Territorio * t) {

	if (pesquisaTerritorio(t->getNome()) > -1) {
		cout << "Este territorio ja foi conquistado." << endl;
		return;
	}

	int resistencia  = (rand() % 6) + 1;
	
	if (forcaMilitar + resistencia > t->getResistencia()) {
		conquistados.push_back(t);
		cout << "Territorio \"" << t->getNome() << "\" conquistado." << endl;
	}
	else {
		cout << "Territorio deu muita luta. Nao foi possivel vencer." << endl;

		if (forcaMilitar > 0) {
			forcaMilitar--;
		}
	}
}

bool Imperio::maisOuro() {
	if (Produtos.getQuantidadeAtual() >= 2) {
		Produtos.rem(2);
		Cofre.add(1);
		return true;
	}
	return false;
}

bool Imperio::maisProdutos() {
	if (Produtos.getQuantidadeAtual() >= 2) {
		Cofre.rem(2);
		Produtos.add(1);
		return true;
	}
	return false;
}



Imperio::~Imperio() {
	conquistados.clear();
}


