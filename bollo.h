#ifndef __BOLLO_H__
#define __BOLLO_H__
using namespace std;
class Bollo{
	private: 
		Data datascadenza;
		float costo;
	public: 
		Bollo(int _kw, int _catEuro);//sono valori che servono per calcolare il costo del bollo e vengono passati 
									 //alla creazione del veicolo	
		Bollo(Data _d, int kw, int _catEuro); //qui si specifica anche la data che verrà inserita nell'oggetto bollo
		setScadenzaB(Data _d);
};                                   



#endif
