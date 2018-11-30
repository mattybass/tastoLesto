#include "privato.h"
#include <string>
#include <iostream>

Privato::Privato(string _nome,string _cognome,string _codFiscale,string _luogoNascita,string _provincia, string _com, string _via, string _cap, int _nCivico):Proprietario(_provincia, _com, _via, _cap, _nCivico),dataNascita(0,0,0){
	nome=_nome;
	cognome=_cognome;
	codFiscale=_codFiscale;
	luogoNascita=_luogoNascita;
	int _gg,_mm,_aa;


	if((convertiStringa(codFiscale,9,1)) < 4){
		sesso='M';
		_gg=convertiStringa(codFiscale,9,2);
		_aa=convertiStringa(codFiscale,6,2);
	}
	else{
		sesso='F';
		_gg=convertiStringa(codFiscale,9,2)-40;
		_aa=convertiStringa(codFiscale,6,2);
	}
	switch(codFiscale.at(8)){
		case 'A':
			_mm=1;
			break;
		case 'B':
			_mm=2;
			break;
		case 'C':
			_mm=3;
			break;
		case 'D':
			_mm=4;
			break;
		case 'E':
			_mm=5;
			break;
		case 'H':
			_mm=6;
			break;
		case 'L':
			_mm=7;
			break;
		case 'M':
			_mm=8;
			break;
		case 'P':
			_mm=9;
			break;
		case 'R':
			_mm=10;
			break;
		case 'S':
			_mm=11;
			break;
		case 'T':
			_mm=12;
			break;																														
		default:
			break;
			
	}
	dataNascita=Data(_gg,_mm,_aa);
	
}

int convertiStringa(string stringa, int inizio, int nCaratteri){
	string sEstratta=stringa.substr(inizio,nCaratteri);
	stringstream ss(sEstratta);
	int i;
  	ss >> i;
  	
  	return i;
}
	


ostream& operator <<(ostream& os,const Privato &p){
	os<<p.nome<<" "<<p.cognome<<endl<<"CODICE FISCALE: "<<p.codFiscale<<endl;
	os<<"DATA DI NASCITA: "<<p.dataNascita<<endl<<"LUOGO DI NASCITA: "<<p.luogoNascita<<endl;
	os<<"SESSO: "<<p.sesso<<endl<<"RESIDENZA: "<<endl<<p.get_residenza();	
	return os;
}
void Privato::stampa()const{
	cout<<nome<<" "<<cognome<<endl<<"CODICE FISCALE: "<<codFiscale<<endl;
	cout<<"DATA DI NASCITA: "<<dataNascita<<endl<<"LUOGO DI NASCITA: "<<luogoNascita<<endl;
	cout<<"SESSO: "<<sesso<<endl<<"RESIDENZA: "<<endl<<get_residenza();
}

void test_privato(){
	Privato p("Riccardo","Ricci","RCCRCR96T17L378O","Trento","TN","Madruzzo","Roma","38076",23);
	cout<<p;

}

