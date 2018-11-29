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

void Veicolo::addAssicurazione(string _compagnia,int _g,int _m,int _a,int _durata){
	listaAssicurazione.push_front(Assicurazione(_compagnia,_g,_m,_a,_durata));
}


void Veicolo::addFurto(int _g, int _m, int _a, string _note, string _luogo){
	listaFurto.push_front(Furto(_g,_m,_a,_note,_luogo));
}

void Veicolo::addRevisione(int _g, int _m, int _a,int _kmRilevati){
	listaRevisione.push_front(Revisione(_g,_m,_a,_kmRilevati,1));
}

void Veicolo::stampaBollo()const{
	cout<<"BOLLO"<<endl;
	list <Bollo>::const_iterator iter;
	for(iter=listaBollo.begin();iter!=listaBollo.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;	
}

void Veicolo::stampaFurto()const{
	cout<<"FURTO"<<endl;
	list <Furto>::const_iterator iter;
	for(iter=listaFurto.begin();iter!=listaFurto.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;
}

void Veicolo::stampaAssicurazione()const{
	cout<<"ASSICURAZIONE"<<endl;
	list <Assicurazione>::const_iterator iter;
	for(iter=listaAssicurazione.begin();iter!=listaAssicurazione.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;		
}

void Veicolo::stampaRevisione()const{
	cout<<"REVISIONE"<<endl;
	list <Revisione>::const_iterator iter;
	for(iter=listaRevisione.begin();iter!=listaRevisione.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;		
}

bool Veicolo::checkRevisione()const{
	list <Revisione>::const_iterator iter;
	iter=listaRevisione.begin();
	if((*iter).get_scadenza()<Data()){
		return 1;
	}
	else{
		return 0;
	}
}	

bool Veicolo::checkAssicurazione()const{
	list <Assicurazione>::const_iterator iter;
	iter=listaAssicurazione.begin();
	if((*iter).get_scadenza()<Data()){
		return 1;
	}
	else{
		return 0;
	}
}

bool Veicolo::checkBollo()const{
	list <Bollo>::const_iterator iter;
	iter=listaBollo.begin();
	if((*iter).get_scadenza()<Data()){
		return 1;
	}
	else{
		return 0;
	}
}

bool Veicolo::checkFurto()const{
	list <Furto>::const_iterator iter;
	iter=listaFurto.begin();
	if(((*iter).get_statoDenuncia()!=1)||iter==listaFurto.end()){ //bool risultava =1 anche senza furti in memoria
		return 0;
	}
	else{
		return 1;
	}
}

void Veicolo::check()const{
	
	cout<<endl<<"REVISIONE: ";
	if(checkRevisione()==1)
		cout<<"non in regola";
	else
		cout<<"in regola";
	
	cout<<endl<<"ASSICURAZIONE: ";
	if(checkAssicurazione()==1)
		cout<<"non in regola";
	else
		cout<<"in regola";
	
	cout<<endl<<"BOLLO: ";
	if(checkBollo()==1)
		cout<<"non in regola";
	else
		cout<<"in regola";
	
	cout<<endl<<"FURTO: ";
	if(checkFurto()==1)
		cout<<"denuncia attiva";
	else
		cout<<"nessuna denuncia attiva";
}	

void Veicolo::disattivaDenuncia(){
	list <Furto>::iterator iter;
	iter=listaFurto.begin();
	(*iter).disattivaDenuncia();	
}
string Veicolo::getTarga()const{
	return targa;
}
ostream& operator<<(ostream& os, const Veicolo& _v){
	os<<"Targa: "<<_v.targa<<endl;
	os<<"Data immatricolazione: "<<_v.dataImmatricolazione<<endl;
	set<TipoVeicolo>::const_iterator temp;
	temp=_v.tipoVeicoloCollegato;
	cout<<*temp;
}


void test_veicolo(){
	Veicolo v("FF657DD",20,11,2018);
//	v.addBollo(3,10,2018);
//	v.stampaBollo();
	v.addFurto(30,1,2018,"Calavino","uomo nero");
	cout<<endl;
	v.disattivaDenuncia();
//	cout<<endl<<"----------------------------"<<endl;
//	v.checkAvviso();
	v.addFurto(30,1,2018,"Calavino","uomo nero");
	v.addAssicurazione("Itas",27,11,2018,5);
	v.addAssicurazione("Axa",20,10,2020,1);

	v.stampaRevisione();
	v.stampaFurto();	
	v.stampaAssicurazione();
	v.stampaBollo();
	cout<<endl<<"----------------------------"<<endl;		
	v.check();
}
