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

	 srand((unsigned)time(0));

	 Territorio* inicial = new TerritorioInicial();
	 mundo.adicionarTerritorio(inicial);
	 
	 Armazem cofre = Armazem(0);
	 Armazem produtos = Armazem(0);

	 imperio = Imperio(inicial, produtos, cofre);

}

void App::MostraMenu() {
	vector<string> menuValues;

	while (1) {
		menuOpt opt = Menu::verMenu(menuValues, turnos);
		if (opt == menuOpt::Terminar) {
			break;
		}
		/*if (opt == menuOpt::Invalido) {
			cout << "apagar territorios" << endl;
			m.~Mundo();
			I.~Imperio();
		}*/
		if (opt != menuOpt::Invalido) {
			Menu::ExecutaComando(opt, menuValues, mundo, imperio, &turnos);
		}
	}
}



