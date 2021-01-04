#include "Imperio.h"
#include "Territorio.h"

using namespace std;


Imperio::Imperio() {
}

Imperio::Imperio( Territorio * inicial, Armazem & Produtos, Armazem & Ouro)
: Produtos(Produtos), Cofre(Ouro), forcaMilitar(0),
capacidadeForcaMilitar(3), podeConquistarIlhas(false), defesasTerritoriais(false){
	conquistados.push_back(inicial);
}

bool Imperio::getTemtrocasComerciais() {
	return trocasComerciais;
}

bool Imperio::getTemDefesasTerritoriais() {
	return defesasTerritoriais;
}


vector<Territorio*>& Imperio::getConquistados() {
	return conquistados;
}

void Imperio::mostraRecursos()const {
	cout << "\t\t Recursos Materiais" << endl;
	cout << "Produtos: " << Produtos.info() << endl;
	cout << "Cofre: " << Cofre.info()  << endl;
}

void Imperio::verTecnologias()const {
	
	cout << "\t\t Tecnologias" << endl;
	if (tecnologias.size() == 0) {
		cout << "Sem tecnologias." << endl;
	}
	for (size_t i = 0; i < tecnologias.size(); i++)
	{
		 cout << tecnologias[i]->getDescricao() << endl;
		 cout << tecnologias[i]->getCustoAsString();
	}

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

Territorio* Imperio::getUltimoConquistado() {
	return conquistados[conquistados.size() - 1];
}

void Imperio::RemoveUltimoConquistado() {
	 conquistados.pop_back();
}

void Imperio::setCapacidadeForcaMilitar(int v) {
	if (v < 0) {
		capacidadeForcaMilitar = 0;
	}
	else {
		capacidadeForcaMilitar = v;
	}

}
void Imperio::setForcaMilitar(int v) {
	if (v > capacidadeForcaMilitar) {
		forcaMilitar = capacidadeForcaMilitar;
	}
	else {
		forcaMilitar = v < 0 ? 0 : v;
	}
}
void Imperio::addForcaMilitar(int v) {
	setForcaMilitar(forcaMilitar + v);
}

void Imperio::listaConquistados()  {
	cout << "\t\t Conquistados " << endl;

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

bool Imperio::conquistaTerritorio(Territorio * t) {
	
	if (t->getCategoria() == categoria::Ilha && !podeConquistarIlhas) {
		cout << "Necessita tec Misseis para conquistar este territorio." << endl;
		return false;
	}
	if (pesquisaTerritorio(t->getNome()) > -1) {
		cout << "Este territorio ja foi conquistado." << endl;
		return false;
	}


	int resistencia  = (rand() % 6) + 1;
	cout << "fator sorte: " << resistencia << " t->getResistencia : " << t->getResistencia() << endl;
	if ((forcaMilitar + resistencia) >= t->getResistencia()) {
		conquistados.push_back(t);
		cout << "Territorio \"" << t->getNome() << "\" conquistado." << endl;
		return true;
	}
	else {
		cout << "Territorio deu muita luta. Nao foi possivel vencer." << endl;
		if (forcaMilitar > 0) {
			forcaMilitar--;
		}
		return true;
	}
}

bool Imperio::forceConquistaTerritorio(Territorio* t) {
	if (t == nullptr) {
		return false;
	}
	if (pesquisaTerritorio(t->getNome()) > -1) {
		cout << "Este territorio ja foi conquistado." << endl;
		return false;
	}
	conquistados.push_back(t);
	return true;
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

bool Imperio::comprarTec(tec t, Tecnologias* pt){
	for (size_t i = 0; i < tecnologias.size(); i++)
	{
		if (tecnologias[i]->getType() == t) {
			return false;
		}
	}
	int c = pt->getCusto();
	if (c <= Cofre.getQuantidadeAtual()) {
		Cofre.rem(c);
		addTec(pt);
		return true;
	}
	return false;
}

void Imperio::addTec(Tecnologias* pt) {
	tecnologias.push_back(pt);

	switch (pt->getType())
	{
	case tec::BancoCentral:
		armazensAumentados = true;
		Cofre.setQuantidadeMax(5);
		Produtos.setQuantidadeMax(5);
		break;
	case tec::BolsaDeValores:
		trocasComerciais = true;
		break;
	case tec::DefesasTerritoriais:
		defesasTerritoriais = true;
		break;
	case tec::MisseisTeleguiados:
		podeConquistarIlhas = true;
		break;
	case tec::DronesMilitares:
		setCapacidadeForcaMilitar(5);
		break;
	default:
		break;
	}
	
}

bool Imperio::forceAdquirirTec(Tecnologias* pt) {
	if (pt != nullptr) {
		addTec(pt);
		return true;
	}
	//cout << "nao foi possivel adicionar tec" << endl;
	return false;
}

bool Imperio::temTec(tec t) {
	for (size_t i = 0; i < tecnologias.size(); i++)
	{
		if (tecnologias[i]->getType() == t) {
			return true;
		}
	}
	return false;
}

void Imperio::RecolherRecursos() {

	for (size_t i = 0; i < conquistados.size(); i++)
	{
		Produtos.add(conquistados[i]->getnProdutos());
		Cofre.add(conquistados[i]->getnOuro());

	}

}

Imperio::~Imperio() {
	conquistados.clear();
}


