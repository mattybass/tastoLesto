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
		bool statoDenuncia;//1->denuncia attiva //0->denuncia ritirata
	public:
		Furto(int _g, int _m, int _a, string _luogo, string _note);
		friend ostream& operator<<(ostream& os, const Furto &f);	
		bool get_statoDenuncia()const;
		void disattivaDenuncia();
};
void test_furto();
ostream& operator<<(ostream& os, const Furto &f);

#endif



