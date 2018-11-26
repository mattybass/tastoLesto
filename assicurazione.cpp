#include "assicurazione.h"
#include "data.h"

Assicurazione::Assicurazione(string _compagnia, int _g,int _m,int _a,int durata):dataScadenzaA(_g,_m,_a+durata),dataInizioA(_g,_m,_a){
	compagnia=_compagnia;
}
void Assicurazione::stampa()const{
	cout<<"COMPAGNIA: "<<compagnia<<endl<<"DATA INIZIO: ";
	dataInizioA.stampa();
	cout<<endl<<"DATA SCADENZA: ";
	dataScadenzaA.stampa();
}

Assicurazione::~Assicurazione(){
}

void test_assicurazione(){
	Assicurazione a("Itas",20,3,2018,5);
	a.stampa();
}


