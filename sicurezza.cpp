#include "sicurezza.h"

Sicurezza::Sicurezza(){
	euroNcap=nAirbag=0;
}
Sicurezza::Sicurezza(int _na, int _ncap){
	euroNcap=_ncap;
	nAirbag=_na;
}
void Sicurezza::stampa()const{
	cout<<"Il veicolo e' fornito di "<<nAirbag<<" airbag, e possiede ";
	cout<<euroNcap<<" stelle."<<endl;

}

void test_sicurezza(){
	Sicurezza s(3,5);
	s.stampa();	
}
