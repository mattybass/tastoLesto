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

void Veicolo::stampaBollo(){
	cout<<"BOLLO"<<endl;
	list <Bollo>::iterator iter;
	for(iter=listaBollo.begin();iter!=listaBollo.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;	
}

void Veicolo::stampaFurto(){
	cout<<"FURTO"<<endl;
	list <Furto>::iterator iter;
	for(iter=listaFurto.begin();iter!=listaFurto.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;
}

void Veicolo::stampaAssicurazione(){
	cout<<"ASSICURAZIONE"<<endl;
	list <Assicurazione>::iterator iter;
	for(iter=listaAssicurazione.begin();iter!=listaAssicurazione.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;		
}

void Veicolo::stampaRevisione(){
	cout<<"REVISIONE"<<endl;
	list <Revisione>::iterator iter;
	for(iter=listaRevisione.begin();iter!=listaRevisione.end();iter++){
		cout<<(*iter);
		cout<<endl<<"----------------------------"<<endl;
	}
	cout<<endl;		
}

void Veicolo::checkRevisione(){
	list <Revisione>::iterator iter;
	iter=listaRevisione.begin();
//	cout<<"REVISIONE: ";
	if((*iter).get_scadenza()<Data()){
		avviso[0]=1;
//		cout<<"scaduta";
	}
	else{
		avviso[0]=0;
//		cout<<"in regola";
	}
}	

void Veicolo::checkAssicurazione(){
	list <Assicurazione>::iterator iter;
	iter=listaAssicurazione.begin();
//	cout<<"ASSICURAZIONE: ";
	if((*iter).get_scadenza()<Data()){
		avviso[1]=1;
//		cout<<"scaduta";
	}
	else{
		avviso[1]=0;
//		cout<<"in regola";
	}
}

void Veicolo::checkBollo(){
	list <Bollo>::iterator iter;
	iter=listaBollo.begin();
//	cout<<"BOLLO: ";
	if((*iter).get_scadenza()<Data()){
		avviso[2]=1;
//		cout<<"scaduto";
	}
	else{
		avviso[2]=0;
//		cout<<"in regola";
	}
}

void Veicolo::checkFurto(){
	list <Furto>::iterator iter;
	iter=listaFurto.begin();
//	cout<<"FURTO: ";
//	cout<<(*iter).get_statoDenuncia()<<endl<<endl;
	if(((*iter).get_statoDenuncia()!=1)||iter==listaFurto.end()){ //bool risultava =1 anche senza furti in memoria
		avviso[3]=0;
//		cout<<"nessuna denuncia attiva";
	}
	else{
		avviso[3]=1;
//		cout<<"denuncia attiva";
	}
}

void Veicolo::checkAvviso(){
	
	checkRevisione();
	checkAssicurazione();
	checkBollo();
	checkFurto();
	
	cout<<endl<<"REVISIONE: ";
	if(avviso[0]==1)
		cout<<"non in regola";
	else
		cout<<"in regola";
	
	cout<<endl<<"ASSICURAZIONE: ";
	if(avviso[1]==1)
		cout<<"non in regola";
	else
		cout<<"in regola";
	
	cout<<endl<<"BOLLO: ";
	if(avviso[2]==1)
		cout<<"non in regola";
	else
		cout<<"in regola";
	
	cout<<endl<<"FURTO: ";
	if(avviso[3]==1)
		cout<<"denuncia attiva";
	else
		cout<<"nessuna denuncia attiva";
}	

void Veicolo::disattivaDenuncia(){
	list <Furto>::iterator iter;
	iter=listaFurto.begin();
	(*iter).disattivaDenuncia();	
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

	
	cout<<endl;
	v.stampaRevisione();
	v.stampaFurto();	
	v.stampaAssicurazione();
	v.stampaBollo();
	cout<<endl<<"----------------------------"<<endl;		
	v.checkAvviso();
}
