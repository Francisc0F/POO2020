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

menuOpt Menu::ProcessaComando(vector<string> & values,  vector<string> & comand_tokens) {
	vector<string>::iterator ptr;

	for (ptr = comand_tokens.begin(); ptr < comand_tokens.end(); ptr++) {
		//cout << "elem: " << *ptr << endl;
		if (*ptr == "x") {
			return menuOpt::Terminar;
		}
		else if (*ptr == "carrega") {
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
		else if (*ptr == "carregaT") {
			ptr++;
			if (ptr != comand_tokens.end()) {
				//cout << "ficheiro: " << *ptr << endl;
				values.push_back(*ptr);
				return menuOpt::CarregaFich;
			}
			else {
				cout << "comando carregaT nome do ficheiro." << endl;
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
		else if (*ptr == "conquista") {
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
		else if (*ptr == "lista") {
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
		else if (*ptr == "maisprod") {
			return menuOpt::MaisProd;
		}
		else if (*ptr == "maisouro") {
			return menuOpt::MaisOuro;
		}
		else if (*ptr == "maismilitar") {
			return menuOpt::MaisMilitar;
		}
		else {
			cout << "Comando Invalido." << endl;
			return menuOpt::Invalido;
		}

	}

}

void Menu::ExecutaComando(menuOpt opt, vector<string> & menuValues, Mundo & m, Imperio & I, int * turno) {

	switch (opt) {

	case menuOpt::CarregaComand: {
		if (m.LerComandosFich(menuValues[0], m, I)) {
			// cout << "lidos";
		}
		break;
	}

	case menuOpt::CarregaFich: {
		if (m.LerFich(menuValues[0])) {
			m.listaTerritorios();
		}
		break;
	}

	case menuOpt::Cria: {
		string nome = menuValues[0];
		int n;
		try { 
			n = stoi(menuValues[1]);
				
		}
		catch (const std::exception& e) {
			//cout << e.what();
			cout << "segundo arg nao e uma valor numerico" << endl;
			break;
		}

		if (n > 0) {
			m.addNTerritorios(n, nome);
			//m.listaTerritorios();
		}
		break;
	}

	case menuOpt::Conquista: {
		int index = m.pesquisaTerritorio(menuValues[0]);
		if (index > -1) {
			I.conquistaTerritorio(m.getTerritorios()[index]);
			if (turno != nullptr) {
				(*turno)++;
			}
			
		}
		else {
			cout << "error case menuOpt::Conquista: nao encontrou territorio com esse nome" << endl;
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
			}
			else {
				cout << "Nao existe territorio." << endl;
			}
			
		}
		
		break;
	}
	
	case menuOpt::Passa: {
		if (turno != nullptr) {
			(*turno)++;
		}
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
		
	default: {
		
		break;
	}
	}
}


menuOpt Menu::verMenu(vector<string> & values, int  turno) {
	values.clear();
	string cmd;
		cout << "\t\tMENU " << endl;
		cout << "--------------------  Turno " << turno << "  -------------------------" << endl;
		cout << "Carrega Ficheiro com Comandos ->  carrega <nomeFich>" << endl;
		cout << "Carrega Territorios diretamente de ficheiro ->  carregaT <nomeFich>" << endl;
		
		cout << "Cria n Territorios ->  cria <tipo> <n>" << endl;
		cout << "Conquista Territorio ->  conquista <nomeTerritorio>" << endl;
		cout << "Passar turno ->  passa" << endl;

		// adicionar recursos
		cout << "Obter mais produtos ->  maisprod" << endl;
		cout << "Obter mais ouro ->  maisouro" << endl;
		cout << "Comprar unidade militar ->  maismilitar" << endl;
		
		cout << "Adquirir tipo de Tecnologia ->  adquire <tipo>" << endl;
		
		cout << "Terminar fase de comandos ->  avanca" << endl;
		
		// estado de jogo
		cout << "Gravar estado de jogo -> grava <nome>" << endl;
		cout << "Retomar gravacao -> ativa <nome>" << endl;
		cout << "Apagar gravacao -> apaga <nome>" << endl;



		cout << "Listar informacao, lista ou lista <nomeTerritorio> ->  lista " << endl;
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


		return Menu::ProcessaComando(values, comand_tokens);
			
}