#ifndef __LUOGO_H__
#define __LUOGO_H__

#include <iostream>

using namespace std;

class Luogo{
	private:
	   string provincia;
	   string comune;
	   string via;
	   string cap;
	   int nCivico;
	public:
		Luogo(string _provincia, string _com, string _via, int _nCivico, string _cap);
		friend ostream& operator<<(ostream& os, const Luogo& _l);
};

ostream& operator<<(ostream& os,const Luogo& _l);

#endif
