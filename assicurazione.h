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
		Assicurazione(string _compagnia, int _g,int _m,int _a,int durata);
		friend ostream& operator<<(ostream& os, const Assicurazione &a);
		Data get_scadenza()const;
};
ostream& operator<<(ostream& os, const Assicurazione &a);

#endif
