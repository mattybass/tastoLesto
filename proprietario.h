#ifndef __PROPRIETARIO_H__
#define __PROPRIETARIO_H__

#include "luogo.h"

using namespace std;

class Proprietario{
	private:
		Luogo residenza;
	public:
		Proprietario(string _provincia, string _com, string _via, string _cap, int _nCivico);
		Luogo get_residenza()const;
};


#endif
