#pragma once
#include <string>
using namespace std;
class Tecnologias
{
protected:
	int custo;
public:
	virtual string getType()const = 0;
};

