#ifndef __LUOGO_H__
#define __LUOGO_H__
#include <string>
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
		Luogo(string _provincia, string _com, string _via, string _cap, int _nCivico);
		friend ostream& operator<<(ostream& os, const Luogo& _l);
};
ostream& operator<<(ostream& os,const Luogo& _l);
void test_luogo();
#endif
