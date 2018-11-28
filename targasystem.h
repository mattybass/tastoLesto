//chechavviso --> dovr� richiamare tutti i check della classe veicolo per un certo veicolo e poi, tramite il getVettore stampare se ci sono avvisi oppure no, pensare
//                se si pu� fare togliendo il vettore di booleani!
#ifndef __TARGASYSTEM_H__
#define __TARGASYSTEM_H__
#include <list>
#include <map>
#include <string>
#include "veicolo.h"
#include "privato.h"
#include "azienda.h"
using namespace std;
class TargaSystem{
	private:
		const string versione;
		map<string,Veicolo> mapPrivati;
		map<string,Veicolo> mapAziende;
		map<string,Privato> mapPropPrivati;
		map<string,Azienda> mapPropAziende;
		//Utility u; da decommentare quando creiamo la classe utility che contiene il map di belfiore e eventuali altre utilities
	public:
		TargaSystem(); //avr� solo il costruttore a 0 parametri
		friend ostream& operator<<(ostream& os, TargaSystem& t);
		void checkAvviso(string _valTarga,string _codFisc="",string _partIva="")const;
		void stampaAuto(string _valTarga)const;
		void addPropPrivati(string _nome,string _cognome,string _codFiscale,string _luogoNascita,string _provincia, string _com, string _via, string _cap, int _nCivico);
		void addPropAziende(string _nomeA,string _pIva,string _provincia, string _com, string _via, string _cap, int _nCivico);
/*		void addPrivati(string _codFiscale,)*/
		
		
		void stampaPropAziende()const;
		void stampaPropPrivati()const;
};
ostream& operator<<(ostream& os, TargaSystem& t);
void test_targasystem();
#endif
