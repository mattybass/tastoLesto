#ifndef __REVISIONE_H__
#define __REVISIONE_H__
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "data.h"

class Revisione{
	private:
		Data dataScadenzaR;
		Data dataInizioR;
		int kmRilevati;
	public:
		Revisione(int _g, int _m, int _a,int _kmRilevati);
		void stampa()const;	
};
void test_revisione();

#endif
