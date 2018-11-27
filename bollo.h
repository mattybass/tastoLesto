#ifndef __BOLLO_H__
#define __BOLLO_H__
#include "data.h"
using namespace std;
class Bollo{
	private: 
		Data dataInizioB;
		Data dataScadenzaB;
		float costo;
	public: 
		Bollo(int _kw, int _catEuro, int _g,int _m,int _a, bool check);//sono valori che servono per calcolare il costo del bollo e vengono passati alla creazione del veicolo	
		friend ostream& operator <<(ostream& os,const Bollo& _b);
		Data get_scadenza()const;

};                
ostream& operator <<(ostream& os,const Bollo& _b);                   
void test_bollo();


#endif
