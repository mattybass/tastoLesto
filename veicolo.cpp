#include "veicolo.h"
#include <list>
#include "bollo.h"
#include "revisione.h"
#include <string>
#include "data.h"

Veicolo::Veicolo(string _targa,int _g,int _m,int _a):dataImmatricolazione(_g,_m,_a){//in veicolo passo la data di immatricolazione
	targa=_targa;
	listaBollo.push_front(Bollo(90,2,_g,_m,_a,0));
	listaRevisione.push_front(Revisione(_g,_m,_a,0,0));	
}

void Veicolo::addBollo(int _g,int _m,int _a){
	listaBollo.push_front(Bollo(90,2,_g,_m,_a,1));
}

void Veicolo::stampaBollo(){
	list <Bollo>::iterator iter;
	for(iter=listaBollo.begin();iter!=listaBollo.end();iter++){
		(*iter).stampa();
		cout<<endl;
	}
}

void Veicolo::addAssicurazione(string _compagnia,int _g,int _m,int _a,int _durata){
	listaAssicurazione.push_front(Assicurazione(_compagnia,_g,_m,_a,_durata));
}


void Veicolo::addFurto(int _g, int _m, int _a, string _note, string _luogo){
	listaFurto.push_front(Furto(_g,_m,_a,_note,_luogo));
}


void Veicolo::addRevisione(int _g, int _m, int _a,int _kmRilevati){
	listaRevisione.push_front(Revisione(_g,_m,_a,_kmRilevati,1));
}

void test_veicolo(){
	Veicolo v("FF657DD",30,12,2018);
	v.stampaBollo();
	cout<<endl;
	v.addBollo(3,3,2019);
	v.stampaBollo();
}
