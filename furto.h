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
};
void test_furto();

#endif



