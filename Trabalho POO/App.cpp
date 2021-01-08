#include "App.h"
#include "Mundo.h"
#include "Imperio.h"

#include "Territorio.h"
#include "Montanha.h"
#include "TerritorioInicial.h"

#include "MisseisTeleguiados.h"
#include "BolsaDeValores.h"
#include "DefesasTerritoriais.h"
#include "DronesMilitares.h"
#include "BancoCentral.h"

#include "Tecnologias.h"
#include "Eventos.h"

#include "RecursoAbandonado.h"
#include "Invasao.h"
#include "AliancaDiplomatica.h"

#include "Menu.h"
#include "GameState.h"

vector<Tecnologias*> App::CreateTecnoList()
{
	vector<Tecnologias*> v;
	v.push_back(new MisseisTeleguiados());
	v.push_back(new DronesMilitares());
	v.push_back(new DefesasTerritoriais());
	v.push_back(new BolsaDeValores());
	v.push_back(new BancoCentral());
	return v;
}
vector<Tecnologias* > App::tecnologias = CreateTecnoList();

vector<Eventos*> App::CreateEventosList()
{
	vector<Eventos*> v;
	v.push_back(new RecursoAbandonado());
	v.push_back(new Invasao());
	v.push_back(new AliancaDiplomatica());
	return v;	
}
vector<Eventos* > App::eventos = CreateEventosList();


App::App(string mode) {
	turnos = 1;
	anos = 1;
	jogoTerminou = false;
	faseAtual = faseTurno::Config;

	srand((unsigned)time(0));

	Territorio* inicial = new TerritorioInicial();
	Menu::mode = "test";
	mundo.adicionarTerritorio(inicial);
	imperio.addT(inicial);
}

Tecnologias* App::getTec(tec t) {
	for (size_t i = 0; i < tecnologias.size(); i++)
	{
		if (tecnologias[i]->getType() == t) {
			return tecnologias[i];
		}
	}
	return nullptr;
}

void App::ConfigMundo() {
	vector<string> menuValues;
	while (1) {
		menuOpt opt = Menu::ComandosConfig(menuValues);
		if (opt == menuOpt::Terminar) {
			break;
		}
		if (opt != menuOpt::Invalido) {
			ExecutaComando(opt, menuValues);
		}
	}
}

void App::FaseSeguinte(int* fase) {
	(*fase)++;
	faseAtual = (faseTurno)(*fase);
}

void App::TurnoSeguinte() {
	if ((turnos + 1) > 6) {
		turnos = 1;
		anos++;
	}
	else {
		turnos++;
	}
}

void App::Jogo() {
	vector<string> menuValues;
	int fase = 1;
	faseAtual = faseTurno::Conquistar;
	int recolhaFeita = 0;

	while (1) {

		while (faseAtual == faseTurno::Conquistar) {
			menuOpt opt = Menu::RecebeComandosJogo(menuValues, faseAtual, imperio, turnos, anos);
			if (opt == menuOpt::Terminar) {
				break;
			}
			if (opt == menuOpt::Invalido) {
				cout << "Comando Invalido." << endl;
			}
			if (opt != menuOpt::Invalido) {
				if (ExecutaComando(opt, menuValues)) { 
					// se comando foi executado com sucesso
					if (!Menu::isDebugComand(opt)) {
						FaseSeguinte(&fase);
					}
				}
			}

		}
		imperio.RecolherRecursos();

		while (faseAtual == faseTurno::Recolha) {
			if (!imperio.temTec(tec::BolsaDeValores)) {
				break;
			}

			menuOpt opt = Menu::RecebeComandosJogo(menuValues, faseAtual, imperio, turnos, anos);
			if (opt == menuOpt::Terminar) {
				break;
			}
			if (opt == menuOpt::Avanca) {
				FaseSeguinte(&fase);
				break;
			}
			if (opt != menuOpt::Invalido) {
				if (ExecutaComando(opt, menuValues)) {
					FaseSeguinte(&fase);
					break;
				}
			}
		}
		
		FaseSeguinte(&fase);

		int nComprasMaisMilitar = 0;
		int nComprasTec = 0;

		while (faseAtual == faseTurno::Comprar) {

			menuOpt opt = Menu::RecebeComandosJogo(menuValues, faseAtual, imperio, turnos, anos);
	
			if (opt == menuOpt::Avanca) {
				FaseSeguinte(&fase);
				break;
			}

			if (nComprasMaisMilitar > 0 && opt == menuOpt::MaisMilitar 
				|| nComprasTec > 0 && opt == menuOpt::AdquireTec) {
				cout << "Comando ja feito neste Turno." << endl;
				continue;
			}

	
			if (opt != menuOpt::Invalido) {
				if (ExecutaComando(opt, menuValues)) {
					if (opt == menuOpt::MaisMilitar) {
						nComprasMaisMilitar++;
					}else if (opt == menuOpt::AdquireTec) {
						nComprasTec++;
					}
					else if (opt == menuOpt::Lista) {
					}
					else {

					}
				}
				else {

				}
			}
		}
		// fase eventos

		string acontecimento;
		GerarEvento(acontecimento);
		if (acontecimento == "InicialConquistado") {
			cout << "Terreno inicial conquista numa invasao. Perdeu " << endl;
			break;
		}
		fase = 0;
		FaseSeguinte(&fase);

		TurnoSeguinte();
	}
	/*if (opt == menuOpt::Invalido) {
		cout << "apagar territorios" << endl;
		m.~Mundo();
		I.~Imperio();
	}*/
}

void App::EventoAlianca() {
	imperio.addForcaMilitar(1);
}

void App::EventoInvasao( string & evento) {
	Territorio* t = imperio.getUltimoConquistado();

	int ataque = (rand() % 6) + 1;
	int forcaAtaque = anos == 1 ? 2 : 3;

	bool temDefesas = imperio.getTemDefesasTerritoriais();

	int resistencia = temDefesas ? t->getResistencia() + 1 : t->getResistencia();

	cout << "ataque : " << (ataque + forcaAtaque) << " defesa: " << resistencia << endl;

	if ((ataque + forcaAtaque) >= resistencia) {
		imperio.RemoveUltimoConquistado();
		evento = "Conquistado";
		if (t->getType() == tipoTerritorio::Inicial) {
			evento = "InicialConquistado";
		}
	}
	else {
		evento = "NadaConquistado";
	}
}

void App::EventoRecursoAbandonado() {
	if (anos == 1) {
		imperio.getProdutos().add(1);
	}
	else {
		imperio.getCofre().add(1);
	}
}

void App::GerarEvento(string & evento) {
	int random = (rand() % 4) + 1;

	random--;
	if (random == 3) {
		cout << "Sem eventos." << endl;
		evento = "sem Evento";
		return;
	}
	else {
		cout << "Evento Escolhido: " << random << endl;
		cout << App::eventos[random]->getDescricao() << endl;

		switch (App::eventos[random]->getType())
		{
		case tipoEvento::Alianca:
			EventoAlianca();
			evento = "alianca";
			break;
		case tipoEvento::Invasao: {
			EventoInvasao(evento);
			break;

		}
		case tipoEvento::RecursoAbandonado: 
			EventoRecursoAbandonado();
			evento = "Recurso Abandonado";
			break;
		}
	}
}

void App::AtualizarProducoes(){
	vector<Territorio*> t = mundo.getTerritorios();

	for (vector<Territorio*>::iterator it = t.begin(); it != t.end(); ++it) {
		switch ((*it)->getType())
		{
		case tipoTerritorio::Planicie:
			if (anos > 1) {
				(*it)->setnProdutos(2);
			}
			break;

		case tipoTerritorio::Montanha:
		/*	if (imperio.pesquisaTerritorio((*it)->getNome()) > -1) {
				Montanha* m = (*it);
				
			}*/

			break;
		case tipoTerritorio::Castelo:
			if (turnos <= 2) {
				(*it)->setnProdutos(2);
			}
			break;
		//case tipoTerritorio::Duna:
		////case tipoTerritorio::Fortaleza:
		//	break;
		//case tipoTerritorio::Pescaria:
		//	break;
		//case tipoTerritorio::Refugio:
		//	break;
		case tipoTerritorio::Mina:
			if (turnos <= 3) {
				(*it)->setnOuro(1);
			}
			else {
				(*it)->setnOuro(2);
			}
			break;
		default:
			break;
		}
	}
}

void App::RecolherRecursoDoImperio() {
	imperio.RecolherRecursos();
}

bool App::LerComandosFich(string nomef) {
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

		menuOpt opt = Menu::ProcessaComando(values, faseTurno::Config, comand_tokens);
		ExecutaComando(opt, values);

	}
	dados.close();

	return true;

}

bool App::ExecutaComando(menuOpt opt, vector<string>& menuValues) {

	switch (opt) {

	case menuOpt::CarregaComand: {
		if (LerComandosFich(menuValues[0])) {
			return true;
		}
		break;
	}

	case menuOpt::Cria: {
		string tipo = menuValues[0];
		int n;
		try {
			n = stoi(menuValues[1]);

		}
		catch (const std::exception& e) {
			//cout << e.what();
			cout << "segundo arg nao e uma valor numerico" << endl;
			return false;
			break;
		}

		tipoTerritorio t = Territorio::validaTipoTerritorio(tipo);
		if (t == tipoTerritorio::Invalido) {
			cout << "tipo Invalido" << endl;
			return false;
			break;
		}

		if (n > 0) {
			mundo.addNTerritorios(n, t);
			//m.listaTerritorios();
			return true;
		}
		break;
	}

	case menuOpt::Conquista: {
		int index = mundo.pesquisaTerritorio(menuValues[0]);
		if (index > -1) {
			return imperio.conquistaTerritorio(mundo.getTerritorios()[index]);;
		}
		else {
			cout << "Nao encontrou territorio com esse nome." << endl;
			return false;
		}
		break;
	}

	case menuOpt::Lista: {
		if (menuValues.empty()) {
			//mundo.listaTerritorios();
			cout << imperio;
		}
		else {
			int index = mundo.pesquisaTerritorio(menuValues[0]);
			if (index > -1) {
				cout << mundo.getTerritorios()[index]->getAsString();
				return true;
			}
			else {
				cout << "Nao existe territorio." << endl;
				return false;
			}

		}

		break;
	}

	case menuOpt::Passa: {
		return true;
		break;
	}

	case menuOpt::MaisOuro: {
		if (imperio.maisOuro()) {
			cout << "troca feita. Produtos -> " << imperio.getCofre().getQuantidadeAtual() << endl;
		}
		else {
			cout << "Sem recursos para fazer troca." << endl;
		}
		break;
	}

	case menuOpt::MaisProd: {
		if (imperio.maisProdutos()) {
			cout << "troca feita. Produtos -> " << imperio.getProdutos().getQuantidadeAtual() << endl;
		}
		else {
			cout << "Sem recursos para fazer troca." << endl;
		}
		break;
	}

	case menuOpt::MaisMilitar: {
		if (imperio.maisMilitar()) {
			cout << "Adicionada unidade de forca militar." << endl;
		}
		else {
			cout << "Nao foi possivel adicionar unidade militar." << endl;
		}
		break;
	}

	case menuOpt::AdquireTec: {

		tec tecno = Tecnologias::tecValida(menuValues[0]);
		if (tecno != tec::Invalida) {
			Tecnologias* t = App::getTec(tecno);
			if (t != nullptr) {
				if (imperio.comprarTec(tecno, t)) {
					return true;
				}
				else {
					cout << "Nao foi Possivel obter a tecnologia." << endl;
					return false;
				}
			}
		}
		else {
			return false;
		}
		break;
	}

	case menuOpt::TomaTec: {
		tec t = Tecnologias::tecValida(menuValues[0]);
		if (t != tec::Invalida) {
			return imperio.forceAdquirirTec(App::getTec(t));
		}
		else {
			cout << "Tec: Nome errado." << endl;
			return false;
		}
		return false;
		break;
	}

	case menuOpt::TomaTerr: {
		int i = mundo.pesquisaTerritorio(menuValues[0]);
		if (i > -1) {
			return imperio.forceConquistaTerritorio(mundo.getTerritorios()[i]);
		}
		cout << "Territorio nao existe" << endl;
		return false;
		break;
	}

	case menuOpt::ModificaOuro:
	case menuOpt::ModificaProd:
		int n;
		try {
			n = stoi(menuValues[0]);

		}
		catch (const std::exception& e) {
			//cout << e.what();
			cout << "arg nao e uma valor numerico" << endl;
			return false;
			break;
		}
		if (opt == menuOpt::ModificaOuro) {
			imperio.getCofre().setQuantidadeAtual(n);
			return true;
		}
		imperio.getProdutos().setQuantidadeAtual(n);
		return true;
		break;
	case menuOpt::ForcaEvento: {

		tipoEvento e = Eventos::validaEvento(menuValues[0]);
		if (e != tipoEvento::Invalido) {
			switch (e)
			{
			case tipoEvento::RecursoAbandonado:
				EventoRecursoAbandonado();
				break;
			case tipoEvento::Invasao: {
				string info;
				EventoInvasao(info);
				cout << info << endl;
				break;
			}
			case tipoEvento::Alianca:
				EventoAlianca();
				break;
			default:
				break;
			}
			return true;
		}
		else {
			cout << "nome evento Invalido, tente -> alianca, invasao, recurso" << endl;
			return false;
		}
		break;
	}
	case menuOpt::Ativa: {
		string nome = menuValues[0];
		cout << "nome grav  " << nome << endl;
		int index = ValidaGravacao(nome);
		if (index > -1) {
			LoadGameState(saves[index]);
			cout << "Retomou: ["<< saves[index]->getNome() << "]"<< endl;
		}
		else {
			cout << "nao foi possivel carregar gravacao" << endl;
			return false;
		}
		break;
	}
	case menuOpt::Apaga:{
		string nome = menuValues[0];
		int index = ValidaGravacao(nome);
		if (index > -1) {
			saves[index]->getNome();
			//apaga
		}
		
		break;
	}
	case menuOpt::Grava: {
		string nome = menuValues[0];
		int index = ValidaGravacao(nome);
		if (index == -1) {
			GameState * a = new GameState(nome, faseAtual, anos, turnos, mundo, imperio);
			saves.push_back(a);
			return true;
		}
		else {
			cout << "Nao foi possivel gravar" << endl;
			return false;
		}
		break;
	}
	case menuOpt::ListaGravacoes: {
		for (size_t i = 0; i < saves.size(); i++){
			cout << saves[i];
		}
		break;
	}
	}
}

void App::LoadGameState(GameState* state) {
	anos = state->getAno();
	turnos = state->getAno();
	faseAtual = state->getfaseAtual();
	//mundo = state->getMundo();
	//imperio = state->getImperio();
}

int App::ValidaGravacao(string nome) {
	for (size_t i = 0; i < saves.size(); i++)
	{
		if (nome == saves[i]->getNome()) {
			return i;
		}
	}
	return -1;
}

void App::Carrega(string fich) {
	vector<string> v;
	v.push_back(fich);
	ExecutaComando(menuOpt::CarregaComand, v);
	cout << "-------------------------------------------" << endl;
}

void App::RelatorioFinal(bool ganhou) {
	int pontos = 0;
	if (ganhou) {
		cout << "\t\tGANHOU! " << endl;
	}
	else {
		cout << "\t\tPERDEU! " << endl;
	}
	cout << "Pontos: " << pontos << endl;
}