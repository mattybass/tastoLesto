#include "bollo.h"

Bollo::Bollo(int _kw, int _catEuro, int _g,int _m,int _a, bool check):dataInizioB(_g,_m,_a),dataScadenzaB(0,0,0){
	if(check==0)//primo bollo della macchina
		dataScadenzaB=Data(_g,_m%12+1,(int(_m/12)+_a));
	else
		dataScadenzaB=Data(_g,_m,_a+1);
	switch(_catEuro){
		case 0:
			if(_kw<=100)
				costo=((float)_kw)*3;
			else
				costo=((float)_kw)*4.5;
			break;				
		case 1:
			if(_kw<=100)
				costo=2.9*((float)_kw);
			else
				costo=((float)_kw)*4.35;
			break;				
		case 2:
			if(_kw<=100)
				costo=((float)_kw)*2.8;
			else
				costo=((float)_kw)*4.2;
			break;
		case 3:
			if(_kw<=100)
				costo=((float)_kw)*2.7;
			else
				costo=((float)_kw)*4.05;
			break;
		case 4:
			if(_kw<=100)
				costo=((float)_kw)*2.7;
			else
				costo=((float)_kw)*4.05;
			break;
		case 5:
			if(_kw<=100)
				costo=((float)_kw)*2.7;
			else
				costo=((float)_kw)*4.05;
			break;
		default:
			break;														
	}	
}

Data Bollo::get_scadenza()const{
	return dataScadenzaB;
}

ostream& operator <<(ostream& os,const Bollo& _b){
	os<<"COSTO BOLLO: "<<_b.costo<<endl<<"DATA INIZIO: "<<_b.dataInizioB<<endl<<"DATA SCADENZA: "<<_b.dataScadenzaB<<endl;
	return os;
}

