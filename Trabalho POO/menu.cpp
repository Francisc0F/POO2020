#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include "menu.h"
using namespace std;

Menu::Menu() {

}


menuOpt Menu::verMenu(vector<string>& values) {
	values.clear();

	string cmd;
	while (true) {
		cout << "\t\tMENU " << endl;
		cout << "----------------------------" << endl;
		cout << "Carrega Territorios ->  carrega <nomeFich>" << endl;
		cout << "Cria n Territorios ->  cria <tipo> <n>" << endl;
		cout << "----------------------------" << endl;

		// usar para nao apanhar ultimo '\n'
		// cin.ignore(numeric_limits<streamsize> ::max(), '\n');
		getline(cin, cmd);

		vector<string> comand_tokens;
		istringstream iss(cmd);

		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(comand_tokens));

		vector<string>::iterator ptr;

		// Displaying vector elements using begin() and end() 
		//	cout << "The vector elements are : " << endl;
		for (ptr = comand_tokens.begin(); ptr < comand_tokens.end(); ptr++) {
			//cout << "elem: " << *ptr << endl;
			if (*ptr == "carrega") {
				ptr++;
				if (ptr != comand_tokens.end()) {
					cout << "ficheiro: " << *ptr << endl;
					values.push_back(*ptr);
					return menuOpt::CarregaFich;
				}
				else {
					cout << "insira nome do ficheiro." << endl;
				}
				break;
			}
			else if (*ptr == "cria") {
				ptr++;
				if (ptr != comand_tokens.end()) {
					cout << "numero de territorios: " << *ptr << endl;
					// cria n territorios
					return menuOpt::Cria;
				}
				else {
					cout << "insira numero de territorios." << endl;
				}
				break;
			}
		}




	}
}