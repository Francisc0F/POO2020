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
using namespace std;

Menu::Menu() {

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
		else if (*ptr == "avancaFase") {
			return menuOpt::AvancarFase;
		}
		else if (*ptr == "avanca") {
			return menuOpt::AvancarTurno;
		}
		else {
			cout << "Comando Invalido." << endl;
			return menuOpt::Invalido;
		}

	}

}

bool Menu::ExecutaComando(menuOpt opt, vector<string>& menuValues, Mundo& m, Imperio& I, int* turno) {

	switch (opt) {

	case menuOpt::CarregaComand: {
		if (m.LerComandosFich(menuValues[0], m, I)) {
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
			m.addNTerritorios(n, t);
			//m.listaTerritorios();
			return true;
		}
		break;
	}

	case menuOpt::Conquista: {
		int index = m.pesquisaTerritorio(menuValues[0]);
		if (index > -1) {
			I.conquistaTerritorio(m.getTerritorios()[index]);
			return true;
		}
		else {
			cout << "Nao encontrou territorio com esse nome." << endl;
			return false;
		}
		break;
	}

	case menuOpt::Lista: {
		if (menuValues.empty()) {
			m.listaTerritorios();
			cout << "\t\t Imperio " << endl;
			I.mostraRecursos();
			I.listaConquistados();
		}
		else {
			int index = m.pesquisaTerritorio(menuValues[0]);
			if (index > -1) {
				cout << m.getTerritorios()[index]->getAsString();
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
		if (I.maisOuro()) {
			cout << "troca feita. Produtos -> " << I.getCofre().getQuantidadeAtual() << endl;
		}
		else {
			cout << "Sem recursos para fazer troca." << endl;
		}
		break;
	}

	case menuOpt::MaisProd: {
		if (I.maisProdutos()) {
			cout << "troca feita. Produtos -> " << I.getProdutos().getQuantidadeAtual() << endl;
		}
		else {
			cout << "Sem recursos para fazer troca." << endl;
		}
		break;
	}
	
	case menuOpt::MaisMilitar: {
		if (I.maisMilitar()) {
			cout << "Adicionada unidade de forca militar." << endl;
		}
		else {
			cout << "Nao foi possivel adicionar unidade militar." << endl;
		}
		break;
	}
	
	case menuOpt::AdquireTec: {
		/*menuValues[0]
		if () {

		*/

		break;
	}
	default: 

		break;
	
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
	return opt == menuOpt::Lista;
}

menuOpt Menu::RecebeComandosJogo(vector<string>& values, faseTurno fase, Imperio I,  int  turno) {
	values.clear();
	string cmd;
	cout << "\t\Comandos Jogo " << endl;
	cout << "--------------------  Turno " << turno << " --- Fase " << (int)fase << "  -------------------------" << endl;

	switch (fase)
	{
	case faseTurno::Conquistar:
		cout << "Conquista Territorio ->  conquista <nomeTerritorio>" << endl;
		cout << "Passar ->  passa" << endl;
		break;
	case faseTurno::Recolha:
		// adicionar recursos
		if (I.temTec("Bolsa Valores")) {
			cout << "Obter mais produtos ->  maisprod" << endl;
			cout << "Obter mais ouro ->  maisouro" << endl;
		}
		else {
			cout << "Compre bolsa de Valores para Obter mais opcoes." << endl;
		}
		break;
	case faseTurno::Comprar:
		cout << "Comprar unidade militar ->  maismilitar" << endl;
		cout << "Adquirir tipo de Tecnologia ->  adquire <tipo>" << endl;
		break;
	case faseTurno::Eventos:
		break;
	default:
		break;
	}
	cout << "--------------------------------------------" << endl;
	// estado de jogo
	cout << "Gravar estado de jogo -> grava <nome>" << endl;
	cout << "Retomar gravacao -> ativa <nome>" << endl;
	cout << "Apagar gravacao -> apaga <nome>" << endl;


	cout << "Listar informacao, lista ou lista <nomeTerritorio> ->  lista " << endl;

	cout << "Terminar fase de comandos ->  avancaFase" << endl;
	cout << "Turno seguinte ->  avancarTurno" << endl;

	cout << "Sair -> x" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "comando: ";

	// usar para nao apanhar ultimo '\n'
	// cin.ignore(numeric_limits<streamsize> ::max(), '\n');

	getline(cin, cmd);

	vector<string> comand_tokens;
	istringstream iss(cmd);

	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(comand_tokens));

	vector<string>::iterator ptr;


	return Menu::ProcessaComando(values, fase, comand_tokens);

}