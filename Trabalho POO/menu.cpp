#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Menu.h"
#include "Mundo.h"
#include "Imperio.h"
#include "Territorio.h"
#include "App.h"
using namespace std;

string Menu::mode;

Menu::Menu() {
	cout << "Construiu Menu" << endl;
}
Menu::Menu(string mode) {
	Menu::mode = mode;
}

bool Menu::isModeTest() {
	return Menu::mode == "test";
}

menuOpt Menu::ProcessaComando(vector<string>& values, faseTurno fase, vector<string>& comand_tokens) {
	vector<string>::iterator ptr;

	for (ptr = comand_tokens.begin(); ptr < comand_tokens.end(); ptr++) {
		//cout << "elem: " << *ptr << endl;
		if (*ptr == "x") {
			return menuOpt::Terminar;
		}
		switch (fase)
		{
		case faseTurno::Config: {
			if (*ptr == "carrega") {
				ptr++;
				if (ptr != comand_tokens.end()) {
					//cout << "ficheiro: " << *ptr << endl;
					values.push_back(*ptr);
					return menuOpt::CarregaComand;
				}
				else {
					cout << "comando carrega precisa do nome do ficheiro." << endl;
				}
				break;
			}
			else if (*ptr == "cria") {
				ptr++;

				if (ptr != comand_tokens.end()) {
					values.push_back(*ptr);
					ptr++;

					if (ptr != comand_tokens.end()) {

						values.push_back(*ptr);
						return menuOpt::Cria;
					}
					else {
						cout << "insira o numero valido de territorios." << endl;
						return menuOpt::Invalido;
					}
				}
				else {
					cout << "insira o tipo valido de territorio." << endl;
					return menuOpt::Invalido;
				}

			}
			break;
		}

		case faseTurno::Conquistar: {
			if (*ptr == "conquista") {
				ptr++;
				ostringstream name;
				if (ptr == comand_tokens.end()) {
					cout << "insira nome do territorio." << endl;
					return menuOpt::Invalido;
				}
				else {
					// constroi nome
					while (ptr != comand_tokens.end()) {
						name << (*ptr) << " ";
						ptr++;
					}
					// cout << "nome do territorio " << name.str() << endl;
					values.push_back(name.str().substr(0, name.str().size() - 1));
					return menuOpt::Conquista;
				}
			}
			else if (*ptr == "passa") {
				return menuOpt::Passa;
			}

			break;
		}

		case faseTurno::Recolha: {
			if (*ptr == "maisprod") {
				return menuOpt::MaisProd;
			}
			else if (*ptr == "maisouro") {
				return menuOpt::MaisOuro;
			}

			break;

		}

		case faseTurno::Comprar: {
			if (*ptr == "maismilitar") {
				return menuOpt::MaisMilitar;
			}
			else if (*ptr == "adquire") {
				ptr++;
				if (ptr != comand_tokens.end()) {
					values.push_back(*ptr);
					return menuOpt::AdquireTec;
				}
				else {
					return menuOpt::Invalido;
				}
			}
			break;
		}

		case faseTurno::Eventos:
			break;
		default:
			break;
		}

		// debug
		if (*ptr == "lista") {
			ptr++;
			ostringstream name;
			if (ptr == comand_tokens.end()) {
				return menuOpt::Lista;
			}
			else {
				while (ptr != comand_tokens.end()) {
					name << (*ptr) << " ";
					ptr++;
				}
				values.push_back(name.str().substr(0, name.str().size() - 1));
				return menuOpt::Lista;
			}
		}
		//else if (*ptr == "avancaFase") {
		//	return menuOpt::AvancarFase;
		//}
		else if (*ptr == "avanca") {
			return menuOpt::Avanca;
		}
		else if (*ptr == "toma") {
			ptr++;
			if (ptr == comand_tokens.end()) {
				return menuOpt::Invalido;
			}
			else {
				if (*ptr == "terr") {
					ptr++;
					if (ptr == comand_tokens.end()) {
						return menuOpt::Invalido;
					}
					else {
						values.push_back(*ptr);
						return menuOpt::TomaTerr;
					}

				}
				else if (*ptr == "tec") {
					ptr++;
					if (ptr == comand_tokens.end()) {
						return menuOpt::Invalido;
					}
					else {
						values.push_back(*ptr);
						return menuOpt::TomaTec;
					}

				}
			}

			return menuOpt::Invalido;
		}
		else if (*ptr == "modifica") {
			ptr++;
			if (ptr == comand_tokens.end()) {
				return menuOpt::Invalido;
			}
			else {
				if (*ptr == "ouro") {
					ptr++;
					if (ptr == comand_tokens.end()) {
						return menuOpt::Invalido;
					}
					else {
						values.push_back(*ptr);
						return menuOpt::ModificaOuro;
					}

				}
				else if (*ptr == "prod") {
					ptr++;
					if (ptr == comand_tokens.end()) {
						return menuOpt::Invalido;
					}
					else {
						values.push_back(*ptr);
						return menuOpt::ModificaProd;
					}

				}
			}
			return menuOpt::Invalido;
		}
		else if (*ptr == "fevento") {
			ptr++;
			if (ptr == comand_tokens.end()) {
				return menuOpt::Invalido;
			}
			values.push_back(*ptr);
			return menuOpt::ForcaEvento;
		}
		else if (*ptr == "grava") {
			ptr++;
			if (ptr == comand_tokens.end()) {
				return menuOpt::Invalido;
			}
			values.push_back(*ptr);
			return menuOpt::Grava;

		}
		else if (*ptr == "ativa") {
			ptr++;
			if (ptr == comand_tokens.end()) {
				return menuOpt::Invalido;
			}
			values.push_back(*ptr);
			return menuOpt::Ativa;
		}
		else if (*ptr == "apaga") {
			ptr++;
			if (ptr == comand_tokens.end()) {
				return menuOpt::Invalido;
			}
			values.push_back(*ptr);
			return menuOpt::Apaga;
		}
		else if (*ptr == "listag") {
		return menuOpt::ListaGravacoes;
		}
		else {
			cout << "Comando Invalido." << endl;
			return menuOpt::Invalido;
		}

	}

}

menuOpt Menu::ComandosConfig(vector<string>& values) {
	values.clear();
	string cmd;
	cout << "Fase configuracao do Mundo:" << endl;
	cout << "Carrega Ficheiro com Comandos ->  carrega <nomeFich>" << endl;
	cout << "Cria n Territorios ->  cria <tipo> <n>" << endl;
	cout << "Terminar config -> seguir" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "comando: ";

	getline(cin, cmd);

	vector<string> comand_tokens;
	istringstream iss(cmd);

	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(comand_tokens));

	vector<string>::iterator ptr;
	ptr = comand_tokens.begin();
	if (*ptr == "seguir") {
		return menuOpt::Terminar;
	}

	return Menu::ProcessaComando(values, faseTurno::Config, comand_tokens);
}

bool Menu::isDebugComand(menuOpt opt) {
	return opt == menuOpt::Lista || opt == menuOpt::ModificaOuro ||
		opt == menuOpt::ModificaProd || opt == menuOpt::TomaTec ||
		opt == menuOpt::Grava || opt == menuOpt::Ativa ||
		opt == menuOpt::Apaga ||
		opt == menuOpt::TomaTerr;
}

menuOpt Menu::RecebeComandosJogo(vector<string>& values, faseTurno fase, Imperio I, int  turno, int ano) {
	values.clear();
	string cmd;
	cout << "-------------------- Ano " << ano << " Turno " << turno << " --- Fase " << (int)fase << "  -------------------------" << endl;

	switch (fase)
	{
	case faseTurno::Conquistar:
		if (Menu::isModeTest()) {
			cout << "conquista <nomeTerritorio>" << endl;
			cout << "passa" << endl;
		}
		else {
			cout << "Conquista Territorio ->  conquista <nomeTerritorio>" << endl;
			cout << "Passar ->  passa" << endl;
		}
		break;
	case faseTurno::Recolha:
		// adicionar recursos
		if (Menu::isModeTest()) {
			if (I.getTemtrocasComerciais()) {
				cout << "maisprod" << endl;
				cout << "maisouro" << endl;
			}

		}
		else {
			if (I.getTemtrocasComerciais()) {
				cout << "Obter mais produtos ->  maisprod" << endl;
				cout << "Obter mais ouro ->  maisouro" << endl;
			}
			else {
				cout << "Compre bolsa de Valores para Obter mais opcoes." << endl;
			}
		}

		break;
	case faseTurno::Comprar:
		if (Menu::isModeTest()) {
			cout << "maismilitar" << endl;
			cout << "adquire <tipo>" << endl;
		}
		else {
			cout << "Comprar unidade militar ->  maismilitar" << endl;
			cout << "Adquirir tipo de Tecnologia ->  adquire <tipo>" << endl;
		}
		break;
	case faseTurno::Eventos:
		break;
	default:
		break;
	}
	cout << "--------------------------------------------" << endl;
	if (Menu::isModeTest()) {
		cout << "grava <nome>" << endl;
		cout << "ativa <nome>" << endl;
		cout << "apaga <nome>" << endl;
		cout << "listag" << endl;
		cout << "lista " << endl;
		cout << "toma <qual> <nome> " << endl;
		cout << "modifica <ouro|prod> N " << endl;
		cout << "fevento <nome-evento>" << endl;
		cout << "avanca" << endl;
		cout << "avancarTurno" << endl;
		cout << "comando: ";
	}
	else {

		// estado de jogo
		cout << "Gravar estado de jogo -> grava <nome>" << endl;
		cout << "Retomar gravacao -> ativa <nome>" << endl;
		cout << "Apagar gravacao -> apaga <nome>" << endl;

		cout << "--------------------------------------------" << endl;
		cout << "Listar informacao, lista ou lista <nomeTerritorio> ->  lista " << endl;
		cout << "Toma de assalto tec ou terr -> toma <qual> <nome> " << endl;
		cout << "Alterar valores -> modifica <ouro|prod> N " << endl;
		cout << "--------------------------------------------" << endl;

		cout << "Proxima fase ->  avanca" << endl;
		cout << "Turno seguinte ->  avancarTurno" << endl;
		cout << "fevento <nome-evento>" << endl;

		cout << "Sair -> x" << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "comando: ";

	}

	// usar para nao apanhar ultimo '\n'
	//cin.ignore(numeric_limits<streamsize> ::max(), '\n');

	getline(cin, cmd);

	vector<string> comand_tokens;
	istringstream iss(cmd);

	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(comand_tokens));

	vector<string>::iterator ptr;


	return Menu::ProcessaComando(values, fase, comand_tokens);

}