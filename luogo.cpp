#include "luogo.h"

Luogo::Luogo(string _provincia, string _com, string _via, string _cap, int _nCivico){
	provincia=_provincia;
	comune=_com;
	via=_via;
	nCivico=_nCivico;
	cap=_cap;
}
ostream& operator<<(ostream& os,const Luogo& _l){
	os<<_l.comune<<" ("<<_l.provincia<<")"<<endl<<"Via "<<_l.via<<", "<<_l.nCivico<<endl<<_l.cap;
	return os;
}
void test_luogo(){
	Luogo l("Trento","Madruzzo","Alcesuron","38072",2);
	cout<<l;
}
