#include "sicurezza.h"

/*Sicurezza::Sicurezza(){
	euroNcap=nAirbag=0;
}*/
Sicurezza::Sicurezza(int _na, int _ncap){
	euroNcap=_ncap;
	nAirbag=_na;
}
int Sicurezza::geteuroNcap()const{
	return euroNcap;
}
int Sicurezza::getnAirbag()const{
	return nAirbag;
}

