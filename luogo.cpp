#include "luogo.h"

Luogo::Luogo(string _provincia, string _com, string _via, string _cap, int _nCivico){
	provincia=_provincia;
	comune=_com;
	via=_via;
	nCivico=_nCivico;
	cap=_cap;
}
ostream& operator<<(ostream& os,const Luogo& _l){
	os<<"Provincia: "<<_l.provincia<<endl<<"Comune: "<<_l.comune<<endl<<"Via: "<<_l.via<<endl<<"Numero civico: "<<_l.nCivico<<endl<<"Cap: "<<_l.cap<<endl;
	return os;
}
void test_luogo(){
	Luogo l("Trento","Madruzzo","Alcesuron","38072",2);
	cout<<l;
}
