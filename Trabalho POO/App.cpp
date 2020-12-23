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


#include "Menu.h"

int App::turnos = 1;
int App::anos = 1;

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


App::App() {
	mundo = Mundo();
	menu = Menu();
	
	faseAtual = faseTurno::Config;

	srand((unsigned)time(0));

	Territorio* inicial = new TerritorioInicial();
	mundo.adicionarTerritorio(inicial);

	Armazem cofre = Armazem(0);
	Armazem produtos = Armazem(0);

	imperio = Imperio(inicial, produtos, cofre);

	
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
			Menu::ExecutaComando(opt, menuValues, mundo, imperio, tecnologias);
		}
	}
}

void App::FaseSeguinte(int* fase) {
	(*fase)++;
	faseAtual = (faseTurno)(*fase);
}

void App::Jogo() {
	vector<string> menuValues;
	int fase = 1;
	faseAtual = faseTurno::Conquistar;
	int recolhaFeita = 0;


	while (1) {

		while (faseAtual == faseTurno::Conquistar) {
			menuOpt opt = Menu::RecebeComandosJogo(menuValues, faseAtual, imperio, turnos);
			if (opt == menuOpt::Terminar) {
				break;
			}
			if (opt != menuOpt::Invalido && opt != menuOpt::AvancarTurno && opt != menuOpt::Lista) {
				if (Menu::ExecutaComando(opt, menuValues, mundo, imperio, tecnologias)) {
					FaseSeguinte(&fase);
				}
			}

		}

		while (faseAtual == faseTurno::Recolha) {
			if (!imperio.temTec("Bolsa de Valores")) {
			
				break;
			}

			menuOpt opt = Menu::RecebeComandosJogo(menuValues, faseAtual, imperio, turnos);
			if (opt == menuOpt::Terminar) {
				break;
			}
			if (opt != menuOpt::Invalido && opt != menuOpt::AvancarTurno && opt != menuOpt::Lista) {
				if (Menu::ExecutaComando(opt, menuValues, mundo, imperio, tecnologias)) {

				}
			}
		}
		imperio.RecolherRecursos();
		FaseSeguinte(&fase);

		int nComprasMaisMilitar = 0;
		int nComprasTec = 0;

		while (faseAtual == faseTurno::Comprar) {

			menuOpt opt = Menu::RecebeComandosJogo(menuValues, faseAtual, imperio, turnos);
	
			if (opt == menuOpt::AvancarFase) {
				FaseSeguinte(&fase);
				break;
			}

			if (nComprasMaisMilitar > 0 && opt == menuOpt::MaisMilitar) {
				cout << "Comando ja feito neste Turno." << endl;
				continue;
			}
			if (nComprasTec > 0 && opt == menuOpt::AdquireTec) {
				cout << "Comando ja feito neste Turno." << endl;
				continue;
			}

	
			if (opt != menuOpt::Invalido && opt != menuOpt::AvancarTurno && opt != menuOpt::Lista) {
				if (Menu::ExecutaComando(opt, menuValues, mundo, imperio, tecnologias)) {
					if (opt == menuOpt::MaisMilitar) {
						nComprasMaisMilitar++;
					}

					if (opt == menuOpt::AdquireTec) {
						nComprasTec++;
					}
				}
			}
		}
		// fase eventos
		


		fase = 0;
		FaseSeguinte(&fase);
		turnos++;
	}
	/*if (opt == menuOpt::Invalido) {
		cout << "apagar territorios" << endl;
		m.~Mundo();
		I.~Imperio();
	}*/
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

void App::Carrega(string fich) {
	vector<string> v;
	v.push_back(fich);
	Menu::ExecutaComando(menuOpt::CarregaComand, v, mundo, imperio, tecnologias);
}