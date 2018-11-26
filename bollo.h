#ifndef __BOLLO_H__
#define __BOLLO_H__
using namespace std;
class Bollo{
	private: 
		Data dataInizioB;
		Data dataScadenzaB;
		float costo;
	public: 
		Bollo(int _kw, int _catEuro, int _g,int _m,int _a);//sono valori che servono per calcolare il costo del bollo e vengono passati 
									 //alla creazione del veicolo	
		setScadenzaB(int _g,int _m,int _a);
};                                   



#endif
