#include "proprietario.h"

Proprietario::Proprietario(string _provincia, string _com, string _via, string _cap, int _nCivico):residenza(_provincia, _com, _via, _cap, _nCivico){
	
}

Luogo Proprietario::get_residenza()const{
	return residenza;
}

