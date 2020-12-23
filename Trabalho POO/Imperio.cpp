#include "Imperio.h"
#include "Territorio.h"

using namespace std;


Imperio::Imperio() {
}

Imperio::Imperio( Territorio * inicial, Armazem & Produtos, Armazem & Ouro)
: Produtos(Produtos), Cofre(Ouro), forcaMilitar(0), capacidadeForcaMilitar(3) {
	conquistados.push_back(inicial);
}

void Imperio::mostraRecursos()const {
	cout << "\t\t Recursos Materiais" << endl;
	cout << "Produtos: " << Produtos.info() << endl;
	cout << "Cofre: " << Cofre.info()  << endl;
}

void Imperio::verTecnologias()const {

}

string Imperio::getForcaMilitar()const {
	ostringstream oss;
	oss << "forcaMilitar: " << forcaMilitar << "; max:" << capacidadeForcaMilitar;
	return oss.str();
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
		cout << endl <<(*ptr)->getAsString() << endl;
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
	cout << "fator sorte: " << resistencia << "t->getResistencia() : " << t->getResistencia() << endl;
	if ((forcaMilitar + resistencia) >= t->getResistencia()) {
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

bool Imperio::maisMilitar() {

	if ((forcaMilitar + 1) > capacidadeForcaMilitar) {
		return false;
	}
	else if(Cofre.getQuantidadeAtual() > 0 && Produtos.getQuantidadeAtual() > 0){
		Cofre.rem(1);
		Produtos.rem(1);
		forcaMilitar++;
		return true;
	}
	return false;
}
bool Imperio::adquirirTec(tec t, Tecnologias* pt){
	for (size_t i = 0; i < tecnologias.size(); i++)
	{
		if (tecnologias[i]->getType() == t) {
			return false;
		}
	}
	int c = pt->getCusto();
	if (c <= Cofre.getQuantidadeAtual()) {
		Cofre.rem(c);
		tecnologias.push_back(pt);
		return true;
	}
	return false;
}

bool Imperio::temTec(string n) {
	return false;
}



void Imperio::RecolherRecursos() {

	for (size_t i = 0; i < conquistados.size(); i++)
	{
		Produtos.add(conquistados[i]->getnOuro());
		Cofre.add(conquistados[i]->getnOuro());

	}

}

Imperio::~Imperio() {
	conquistados.clear();
}


