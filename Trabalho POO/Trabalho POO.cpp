// Trabalho POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
#include <sstream>
#include <fstream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include "Mundo.h"
#include "Menu.h"
#include "Imperio.h"
using namespace std;

int main()
{
	// const string testf = "territorios.txt";
	Mundo m = Mundo();
	Imperio I = Imperio();

	vector<string> menuValues;
	


	while (1) {
		menuOpt opt = Menu::verMenu(menuValues);

		if (opt == menuOpt::Terminar) {
			break;
		}

		switch (opt) {

		case menuOpt::CarregaFich: {
			if (m.LerFich(menuValues[0])) {
				m.listaTerritorios();
			}
			break;
		}

		case menuOpt::Cria: {
			int n = stoi(menuValues[0]);
			cout << n;

			if (n > 0) {
				m.addNTerritorios(n);
				m.listaTerritorios();
			}

			break;
		}

		case menuOpt::Conquista: {
			//cout << "\"" << menuValues[0] << "\"" << endl;
			int index = m.pesquisaTerritorio(menuValues[0]);
			if (index > -1) {
				I.conquistaTerritorio(m.getTerritorios()[index]);
			}
			else {
				cout << "error case menuOpt::Conquista: nao encontrou territorio com esse nome";
			}
			break;
		}

		case menuOpt::Lista: {

		}
		case menuOpt::Passa: {
			int n = stoi(menuValues[0]);
			cout << n;

			if (n > 0) {
				m.addNTerritorios(n);
				m.listaTerritorios();
			}

			break;
		}
		default: {
			break;
		}
		}
	}
	
}
