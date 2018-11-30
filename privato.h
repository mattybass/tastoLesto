#ifndef __PRIVATO_H__
#define __PRIVATO_H__
#include "utility.h"
#include "luogo.h"
#include "proprietario.h"
#include "data.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

class Privato:public Proprietario{
	private:
		string nome;
		string cognome;
		string codFiscale;
		string luogoNascita;
		Data dataNascita;
		char sesso;
	public:
		Privato(string _nome,string _cognome,string _codFiscale,string _luogoNascita,string _provincia, string _com, string _via, int _nCivico,string _cap);
		friend ostream& operator <<(ostream& os,const Privato &p);
		void stampa()const;
};

ostream& operator <<(ostream& os,const Privato &p);
void test_privato();

//int convertiStringa(string stringa, int inizio, int nCaratteri);

#endif
