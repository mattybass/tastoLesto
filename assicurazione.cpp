#include "assicurazione.h"

Assicurazione::Assicurazione(string _compagnia, int _g,int _m,int _a):dataScadenza(_g,_m,_a),dataInizio(_g,_m,_a){
	compagnia=_compagnia;
}

Assicurazione::setScadenza(int _g,int _m,int _a, int durata):dataScadenza(_g,_m,_a+durata),dataInizio(_g,_m,_a){
	
}

Assicurazioen::setAssicurazione(string _compagnia, int _g,int _m,int _a,durata):dataScadenza(_g,_m,_a+durata),dataInizio(_g,_m,_a){
	compagnia=_compagnia;
}
