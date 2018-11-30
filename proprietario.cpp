#include "proprietario.h"

Proprietario::Proprietario(string _provincia, string _com, string _via, int _nCivico, string _cap):residenza(_provincia, _com, _via, _nCivico,_cap){
	
}

Luogo Proprietario::get_residenza()const{
	return residenza;
}

