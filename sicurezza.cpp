#include "sicurezza.h"

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

ostream& operator<<(ostream& os, const Sicurezza& s){
	os<<"Stelle EuronCap: "<<s.euroNcap<<endl<<"Numero airbag: "<<s.nAirbag<<endl;
}

