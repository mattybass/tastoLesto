#ifndef __ASSICURAZIONE_H__
#define __ASSICURAZIONE_H__
#include <string>
#include <iostream>
#include "data.h"
using namespace std;

class Assicurazione{
	private:
		Data dataInizioA;
		Data dataScadenzaA;
		string compagnia;
	public:
		friend ostream& operator<<(ostream& os, const Assicurazione &a);
		Assicurazione(string _compagnia, int _g,int _m,int _a,int durata);
};
ostream& operator<<(ostream& os, const Assicurazione &a);
void test_assicurazione();

#endif
