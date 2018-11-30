#include "sicurezza.h"

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

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

