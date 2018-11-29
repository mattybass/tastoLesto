//chechavviso --> dovrà richiamare tutti i check della classe veicolo per un certo veicolo e poi, tramite il getVettore stampare se ci sono avvisi oppure no, pensare
//                se si può fare togliendo il vettore di booleani!
#ifndef __TARGASYSTEM_H__
#define __TARGASYSTEM_H__
#include <list>
#include <map>
#include <string>
#include <set>

#include "tipoveicolo.h"
#include "veicolo.h"
#include "privato.h"
#include "azienda.h"
using namespace std;
class TargaSystem{
	private:
		const string versione;
		set<TipoVeicolo> setTipoVeicolo;
		map<string,list<Veicolo> > mapPrivati;
		map<string,list<Veicolo> > mapAziende;
		map<string,Privato> mapPropPrivati;
		map<string,Azienda> mapPropAziende;
		//Utility u; da decommentare quando creiamo la classe utility che contiene il map di belfiore e eventuali altre utilities
	public:
		TargaSystem(); //avrò solo il costruttore a 0 parametri
		friend ostream& operator<<(ostream& os, TargaSystem& t);
		void checkAvvisoPrivati(string _valTarga,string _codFisc="",string _partIva="")const;
		void stampaAuto(string _valTarga)const;
		bool searchAuto(string _valTarga)const;
		void addPropPrivati(string _nome,string _cognome,string _codFiscale,string _luogoNascita,string _provincia, string _com, string _via, string _cap, int _nCivico);
		void addPropAziende(string _nomeA,string _pIva,string _provincia, string _com, string _via, string _cap, int _nCivico);
		void addPrivati(string _codFiscale,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag);
		void addAziende(string _pIva,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag);
		
		void stampaPropAziende()const;
		void stampaPropPrivati()const;
		
		set<TipoVeicolo>::iterator searchTipoVeicolo(Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag);
};
ostream& operator<<(ostream& os, TargaSystem& t);
void test_targasystem();
#endif
