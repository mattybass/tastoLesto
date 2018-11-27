#include "assicurazione.h"
#include "data.h"

Assicurazione::Assicurazione(string _compagnia, int _g,int _m,int _a,int durata):dataScadenzaA(_g,_m,_a+durata),dataInizioA(_g,_m,_a){
	compagnia=_compagnia;
}

Data Assicurazione::get_scadenza()const{
	return dataScadenzaA;
}

ostream& operator<<(ostream& os, const Assicurazione &a){
	os<<"COMPAGNIA ASSICURATIVA: "<<a.compagnia<<endl<<"DATA INIZIO: "<<a.dataInizioA<<endl<<"DATA SCADENZA: "<<a.dataScadenzaA;
	return os;
}

void test_assicurazione(){
	Assicurazione a("Itas",20,3,2018,5);
	cout<<a;
}

