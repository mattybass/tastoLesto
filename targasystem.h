//chechavviso --> dovrà richiamare tutti i check della classe veicolo per un certo veicolo e poi, tramite il getVettore stampare se ci sono avvisi oppure no, pensare
//                se si può fare togliendo il vettore di booleani!
#ifndef __TARGASYSTEM_H__
#define __TARGASYSTEM_H__
#include <list>
#include <map>
#include <string>
#include "veicolo.h"
using namespace std;
class TargaSystem{
	private:
		const string versione;
		map<string,list<Veicolo> > mapPrivati;
		map<string,list<Veicolo> > mapAziende;
		//Utility u; da decommentare quando creiamo la classe utility che contiene il map di belfiore e eventuali altre utilities
	public:
		TargaSystem(); //avrò solo il costruttore a 0 parametri
		friend ostream& operator<<(ostream& os, TargaSystem& t);
		void checkAvviso(string _valTarga,string _codFisc="",string _partIva="")const;
		void stampaAuto(string _valTarga)const;
};
ostream& operator<<(ostream& os, TargaSystem& t);
void test_targasystem();
#endif
