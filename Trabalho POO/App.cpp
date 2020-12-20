#include "App.h"
#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
#include "TerritorioInicial.h"
#include "Menu.h"

int App::turnos = 1;

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


void App::ConfigMundo() {
	vector<string> menuValues;
	while (1) {
		menuOpt opt = Menu::ComandosConfig(menuValues);
		if (opt == menuOpt::Terminar) {
			break;
		}
		if (opt != menuOpt::Invalido) {
			Menu::ExecutaComando(opt, menuValues, mundo, imperio, &turnos);
		}
	}
}

menuOpt App::FaseRecolha(vector<string>& values, int  turno) {
	values.clear();
	string cmd;
	cout << "Obter mais produtos ->  maisprod" << endl;
	cout << "Obter mais ouro ->  maisouro" << endl;

	getline(cin, cmd);

	vector<string> comand_tokens;
	istringstream iss(cmd);

	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(comand_tokens));

	vector<string>::iterator ptr;


	return Menu::ProcessaComando(values, faseTurno::Recolha, comand_tokens);
}

void App::Jogo() {
	vector<string> menuValues;
	int fase = 1;
	faseAtual = faseTurno::Conquistar;
	int recolhaFeita = 0;


	while (1) {
		menuOpt opt = Menu::RecebeComandosJogo(menuValues, faseAtual, turnos);
		if (opt == menuOpt::Terminar) {
			break;
		}

		if (opt != menuOpt::Invalido && opt != menuOpt::Avancar) {
			Menu::ExecutaComando(opt, menuValues, mundo, imperio, &turnos);
		}

		if (opt != menuOpt::Avancar) {
			switch (faseAtual)
			{
			case faseTurno::Recolha: {
		/*		if (recolhaFeita == 0) {
					FaseRecolha();
					recolhaFeita = 1;
				}*/
				break;
			}
			case faseTurno::Comprar:
				break;
			case faseTurno::Eventos:
				break;
			default:
				break;
			}

			if (!Menu::isDebugComand(opt)) {
				fase++;
				if (fase > 3) {
					turnos++;
					fase = 1;
				}
				faseAtual = (faseTurno)fase;
			}
		}
		else {
			if (recolhaFeita == 0) {
				RecolherRecursoDoImperio();
				recolhaFeita = 1;
			}
			turnos++;
			fase = 1;
			faseAtual = (faseTurno)fase;
			recolhaFeita = 0;
		}



	}
	/*if (opt == menuOpt::Invalido) {
		cout << "apagar territorios" << endl;
		m.~Mundo();
		I.~Imperio();
	}*/
}

void App::RecolherRecursoDoImperio() {
	imperio.RecolherRecursos();
}

void App::Carrega(string fich) {
	vector<string> v;
	v.push_back(fich);
	Menu::ExecutaComando(menuOpt::CarregaComand, v, mundo, imperio, &turnos);
}



