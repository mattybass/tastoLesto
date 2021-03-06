#include "furto.h"

Furto::Furto(int _g, int _m, int _a, string _luogo, string _note):dataDenuncia(_g,_m,_a){
	statoDenuncia=1;
	luogoDenuncia=_luogo;
	noteDenuncia=_note;
}
bool Furto::get_statoDenuncia()const{
	return statoDenuncia;
}

void Furto::disattivaDenuncia(){
	statoDenuncia=0;
}

ostream& operator<<(ostream& os, const Furto &f){
	os<<"DATA DENUNCIA: "<<f.dataDenuncia<<endl<<"LUOGO DENUNCIA: "<<f.luogoDenuncia<<endl<<"NOTE: "<<f.noteDenuncia<<endl<<"STATO DENUNCIA: ";
	if(f.statoDenuncia==1){
		os<<"attiva";
	}
	else
		os<<"ritirata";
	os<<endl;
	return os;
}
