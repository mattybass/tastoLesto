#include "azienda.h"

Azienda::Azienda(string _nomeA,string _pIva,string _provincia, string _com, string _via, int _nCivico,string _cap):Proprietario(_provincia, _com, _via, _nCivico,_cap){
	nomeA=_nomeA;
	pIva=_pIva;
}

ostream& operator <<(ostream& os,const Azienda &a){
	os<<a.nomeA<<endl<<"P.IVA: "<<a.pIva<<endl<<endl<<"SEDE LEGALE"<<endl<<a.get_residenza();
	return os;
}

void Azienda::stampa()const{
	cout<<nomeA<<endl<<"P.IVA: "<<pIva<<endl<<endl<<"SEDE LEGALE"<<endl<<get_residenza();
}
void test_azienda(){
	Azienda a("Mario Povoli elettricista","0000168486","TN","Vallelaghi","al Picarel",11,"38090");
	cout<<a;
}
