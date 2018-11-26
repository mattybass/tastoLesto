#ifndef __ASSICURAZIONE_H__
#define __ASSICURAZIONE_H__
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "data.h"

class Assicurazione{
	private:
		Data dataInizio;
		Data dataScadenza;
		string compagnia;
	public:
		Assicurazione(string _compagnia, int _g,int _m,int _a);
		setScadenza(int _g,int _m,int _a);
		setAssicurazione(string _compagnia, int _g,int _m,int _a);
		
};
