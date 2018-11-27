#include "furto.h"

Furto::Furto(int _g, int _m, int _a, string _note, string _luogo):dataDenuncia(_g,_m,_a){
	luogoDenuncia=_luogo;
	noteDenuncia=_note;
}

void Furto::stampa()const{
	cout<<"DATA DENUNCIA: "<<dataDenuncia<<endl<<"LUOGO DENUNCIA: "<<luogoDenuncia<<endl<<"NOTE: "<<noteDenuncia;
}

void test_furto(){
	Furto f(30,1,1998,"Mi hanno ciavato la polo","Calavino");
	cout<<f;
}

ostream& operator<<(ostream& os, const Furto &f){
	os<<"DATA DENUNCIA: "<<f.dataDenuncia<<endl<<"LUOGO DENUNCIA: "<<f.luogoDenuncia<<endl<<"NOTE: "<<f.noteDenuncia;
	
//	<<"DATA SCADENZA: "<<f.dataScadenzaR<<endl<<"KM RILEVATI: "<<_r.kmRilevati<<endl;
	return os;
}
