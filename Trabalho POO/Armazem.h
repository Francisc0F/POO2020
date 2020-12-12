#pragma once
#include <string>

using namespace std;


class Armazem
{
	int quantidadeAtual;
	int quantidadeMax;

	

public:
	Armazem(int quantInicial = 0, int max = 3);

	int getQuantidadeAtual()const;
	int getQuantidadeMax()const;
	

	//setters
	void setQuantidadeAtual(int n);
	void setQuantidadeMax(int n);
	string info()const;

	void add(int n);
	void rem(int n);
};

