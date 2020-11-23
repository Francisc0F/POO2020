#include "menu.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

void menu::verMenu() {
	string cmd;
	while (1) {
		cout << "\t\tMENU " <<  endl;
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
		cout << "The vector elements are : " << endl;
		for (ptr = comand_tokens.begin(); ptr < comand_tokens.end(); ptr++)
			cout << "elem: " << *ptr  << endl;


		//cout << "comando: " << cmd << endl;
	}
}