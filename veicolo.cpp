#include "veicolo.h"

Veicolo::Veicolo(string _targa,set<TipoVeicolo>::iterator _tipoVeicoloCollegato,int _g,int _m,int _a):dataImmatricolazione(_g,_m,_a){//in veicolo passo la data di immatricolazione
	targa=_targa;
	tipoVeicoloCollegato=_tipoVeicoloCollegato;
	listaBollo.push_front(Bollo(90,2,_g,_m,_a,0));
	listaRevisione.push_front(Revisione(_g,_m,_a,0,0));	
}

void Veicolo::addBollo(int _g,int _m,int _a){
	list<Bollo>::const_iterator iter;
	iter=listaBollo.begin();
	if((iter->get_scadenza())<(Data(_g,_m,_a))){
		cout<<"Attenzione! Bollo precendente scaduto in data "<<(iter->get_scadenza())<<endl;		
	}	
	listaBollo.push_front(Bollo(90,2,_g,_m,_a,1));
}

void Veicolo::addAssicurazione(string _compagnia,int _g,int _m,int _a,int _durata){
	list<Assicurazione>::const_iterator iter;
	iter=listaAssicurazione.begin();
	if(((iter->get_scadenza())<(Data(_g,_m,_a))) && listaAssicurazione.begin()!=listaAssicurazione.end()){	
		cout<<"Attenzione! Assicurazione precendente scaduta in data "<<(iter->get_scadenza())<<endl;		
	}
	listaAssicurazione.push_front(Assicurazione(_compagnia,_g,_m,_a,_durata));
}


void Veicolo::addFurto(int _g, int _m, int _a, string _note, string _luogo){
	listaFurto.push_front(Furto(_g,_m,_a,_luogo,_note));
}

void Veicolo::addRevisione(int _g, int _m, int _a,int _kmRilevati){
	list<Revisione>::const_iterator iter;
	iter=listaRevisione.begin();
	if(((iter->get_scadenza())<(Data(_g,_m,_a))) && listaRevisione.begin()!=listaRevisione.end()){
		cout<<"Attenzione! Revisione precendente scaduta in data "<<(iter->get_scadenza())<<endl;		
	}

	listaRevisione.push_front(Revisione(_g,_m,_a,_kmRilevati,1));
}

void Veicolo::stampaBollo()const{
	cout<<"BOLLO"<<endl;
	list <Bollo>::const_iterator iter;
	for(iter=listaBollo.begin();iter!=listaBollo.end();iter++){
		cout<<(*iter);
		cout<<"----------------------------"<<endl;
	}
	cout<<endl;	
}

void Veicolo::stampaFurto()const{
	cout<<"FURTO"<<endl;
	list <Furto>::const_iterator iter;
	iter=listaFurto.begin();
	if(iter!=listaFurto.end()){
	for(iter;iter!=listaFurto.end();iter++){
		cout<<(*iter);
		cout<<"----------------------------"<<endl;
	}
	cout<<endl;
	}
	else
		cout<<"Ancora nessun furto!"<<endl;
}

void Veicolo::stampaAssicurazione()const{
	cout<<"ASSICURAZIONE"<<endl;
	list <Assicurazione>::const_iterator iter;
	iter=listaAssicurazione.begin();
	if(iter!=listaAssicurazione.end()){
	for(iter=listaAssicurazione.begin();iter!=listaAssicurazione.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;	
	}
	else	
		cout<<"Ancora nessuna assicurazione!"<<endl;
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
	cout<<"----------------------"<<endl<<"AVVISI VEICOLO "<<targa<<endl<<"----------------------"<<endl;
	cout<<"REVISIONE: ";
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
		cout<<"denuncia attiva"<<endl;
	else
		cout<<"nessuna denuncia attiva"<<endl;
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

