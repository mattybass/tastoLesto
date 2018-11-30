#include "luogo.h"

using namespace std;

Luogo::Luogo(string _provincia, string _com, string _via, int _nCivico, string _cap){
	provincia=_provincia;
	comune=_com;
	via=_via;
	nCivico=_nCivico;
	cap=_cap;
}

ostream& operator<<(ostream& os,const Luogo& _l){
	os<<"Comune di "<<_l.comune<<" ("<<_l.provincia<<")"<<endl<<"Via "<<_l.via<<", "<<_l.nCivico<<endl<<"Cap "<<_l.cap;
	return os;
}

