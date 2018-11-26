#ifndef __ASSICURAZIONE_H__
#define __ASSICURAZIONE_H__
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "data.h"

class Assicurazione{
	private:
		Data dataInizioA;
		Data dataScadenzaA;
		string compagnia;
	public:
		Assicurazione(string _compagnia, int _g,int _m,int _a,int durata);
		~Assicurazione();
//		void setScadenza(int _g,int _m,int _a,int durata);
//		void setAssicurazione(string _compagnia, int _g,int _m,int _a,int durata);
		void stampa()const;
};
void test_assicurazione();

#endif
