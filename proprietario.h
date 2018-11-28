#ifndef __PROPRIETARIO_H__
#define __PROPRIETARIO_H__
#include <string>
#include "luogo.h"

using namespace std;

class Proprietario{
	private:
		Luogo residenza;
	public:
		Proprietario(string _provincia, string _com, string _via, string _cap, int _nCivico);
	//	friend ostream& operator <<(ostream& os,Proprietario &p);
		Luogo get_residenza()const;
};

//ostream& operator <<(ostream& os,Proprietario &p);


#endif
