#ifndef __PRIVATO_H__
#define __PRIVATO_H__
#include "luogo.h"
#include "proprietario.h"
#include "data.h"
#include <string>

class Privato:public Proprietario{
	private:
		string nome;
		string cognome;
		string codFiscale;
		string luogoNascita;
		Data dataNascita;
		char sesso;
	public:
		Privato(string _nome,string _cognome,string _codFiscale,string luogoNascita);
		friend ostream& operator <<(ostream& os,Privato &p);
};

ostream& operator <<(ostream& os,Privato &p);
void test_privato();
#endif
