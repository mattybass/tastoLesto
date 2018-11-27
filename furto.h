#ifndef __FURTO_H__
#define __FURTO_H__
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "data.h"

class Furto{
	private:
		Data dataDenuncia;
		string luogoDenuncia;
		string noteDenuncia;
	public:
		Furto(int _g, int _m, int _a, string _note, string _luogo);
		void stampa()const;
		friend ostream& operator<<(ostream& os, const Furto &f);	
};
void test_furto();
ostream& operator<<(ostream& os, const Furto &f);

#endif



