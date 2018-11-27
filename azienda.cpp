#ifndef __AZIENDA_H__
#define __AZIENDA_H__
#include "luogo.h"
#include <string>

class Azienda:public Proprietario{
	private:
		string nomaAz;//nome azineda
		int pIva; 
		Luogo sede; //ubicazione dell'azienda
	public:
		Azienda(string _n,int _p, Luogo _l);
	
};
#endif
