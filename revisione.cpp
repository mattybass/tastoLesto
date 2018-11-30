#include "revisione.h"

Revisione::Revisione(int _g, int _m, int _a,int _kmRilevati,bool check):dataScadenzaR(_g,_m%12+1,int(_m/12)+_a+4),dataInizioR(_g,_m,_a){
	if(check==1)
		dataScadenzaR=Data(_g,_m%12+1,int(_m/12)+_a+2);
	kmRilevati=_kmRilevati;
}

Data Revisione::get_scadenza()const{
	return dataScadenzaR;
}

ostream& operator <<(ostream& os,const Revisione& _r){
	os<<"DATA INIZIO: "<<_r.dataInizioR<<endl<<"DATA SCADENZA: "<<_r.dataScadenzaR<<endl<<"KM RILEVATI: "<<_r.kmRilevati;
	return os;
}

