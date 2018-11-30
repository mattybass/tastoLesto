#ifndef __AZIENDA_H__
#define __AZIENDA_H__
#include "proprietario.h"

using namespace std;

class Azienda:public Proprietario{
	private:
		string pIva;
		string nomeA;//nome azienda 
	public:
		Azienda(string _nomeA,string _pIva,string _provincia, string _com, string _via, int _nCivico, string _cap);
		friend ostream& operator <<(ostream& os,const Azienda &a);
		void stampa()const;
};

ostream& operator <<(ostream& os,const Azienda &a);

#endif
