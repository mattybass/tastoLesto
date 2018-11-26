#include "bollo.h"
#include "data.h"

Bollo::Bollo(int _kw, int _catEuro, int _g,int _m,int _a):dataScadenzaB(_g,_m%12+1,int(_m/12)+_a),dataInizioB(_g,_m,_a){
	switch(_catEuro){
		case 0:
			if(_kw<=100)
				costo=(float)(_kw*3);
			else
				costo=(float)(_kw*4.5);
			break;				
		case 1:
			if(_kw<=100)
				costo=(float)(2.9*_kw);
			else
				costo=(float)_kw*4.35;
			break;				
		case 2:
			if(_kw<=100)
				costo=(float)_kw*2.8;
			else
				costo=(float)_kw*4.2;
			break;
		case 3:
			if(_kw<=100)
				costo=(float)_kw*2.7;
			else
				costo=(float)_kw*4.05;
			break;
		case 4:
			if(_kw<=100)
				costo=(float)_kw*2.7;
			else
				costo=(float)_kw*4.05;
			break;
		case 5:
			if(_kw<=100)
				costo=(float)_kw*2.7;
			else
				costo=(float)_kw*4.05;
			break;
		default:
			break;														
	}	
}

void Bollo::stampa()const{
	cout<<"COSTO BOLLO: "<<costo<<endl<<"DATA INIZIO: "<<dataInizioB<<endl<<"DATA SCADENZA: "<<dataScadenzaB;
}

void test_bollo(){
	Bollo b(80,1,30,1,2018);
	b.stampa();
}
