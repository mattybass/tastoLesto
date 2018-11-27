#include "revisione.h"

Revisione::Revisione(int _g, int _m, int _a,int _kmRilevati,bool check):dataScadenzaR(_g,_m%12+1,int(_m/12)+_a+4),dataInizioR(_g,_m,_a){
	if(check==1)
		dataScadenzaR=Data(_g,_m%12+1,int(_m/12)+_a+2);
	kmRilevati=_kmRilevati;
}

ostream& operator <<(ostream& os,const Revisione& _r){
	os<<"DATA INIZIO: "<<_r.dataInizioR<<endl<<"DATA SCADENZA: "<<_r.dataScadenzaR<<endl<<"KM RILEVATI: "<<_r.kmRilevati<<endl;
	return os;
}

void test_revisione(){
	Revisione r(30,1,2018,20690,0);
	cout<<r;
}
