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
#include "utility.h"
using namespace std;
class TargaSystem{
	private:
		const string versione;
		set<TipoVeicolo> setTipoVeicolo;
		map<string,list<Veicolo> > mapPrivati;
		map<string,list<Veicolo> > mapAziende;
		map<string,Privato> mapPropPrivati;
		map<string,Azienda> mapPropAziende;
		Utility u;
		
	public:
		TargaSystem(); 
		//FUNZIONALITA' PER L'UTENTE
		//Metodi di aggiunta:
		void addPropPrivati(string _nome,string _cognome,string _codFiscale,string _provincia, string _com, string _via, int _nCivico, string _cap);
		void addPropAziende(string _nomeA,string _pIva,string _provincia, string _com, string _via, int _nCivico,string _cap);
		void addPrivati(string _codFiscale,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag);
		void addAziende(string _pIva,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag);
		void addBollo(string _valTarga,int _g,int _m,int _a, string _codFisc="",string _partIva="");
		void addAssicurazione(string _valTarga,int _g,int _m,int _a, int _anniDurata, string _compagnia, string _codFisc="",string _partIva="");
		void addFurto(string _valTarga,int _g,int _m,int _a, string _luogoDenuncia, string _noteDenuncia, string _codFisc="",string _partIva="");
		void addRevisione(string _valTarga,int _g,int _m,int _a, int _kmRilevati, string _codFisc="",string _partIva="");
		//Metodi di stampa:
		void stampaProp(string _valTarga)const;
		void stampaAuto(string _valTarga)const;
		void stampaBollo(string _valTarga,string _codFisc="",string _partIva="")const;
		void stampaFurto(string _valTarga,string _codFisc="",string _partIva="")const;
		void stampaAssicurazione(string _valTarga,string _codFisc="",string _partIva="")const;
		void stampaRevisione(string _valTarga,string _codFisc="",string _partIva="")const;
		void stampaPropAziende()const;//stampa tutti i proprietari privati
		void stampaPropPrivati()const;//stampa tutte le aziende proprietarie
		//Altri metodi
		void disattivaDenuncia(string _valTarga,string _codFisc="",string _partIva="");
		void checkAvviso(string _valTarga,string _codFisc="",string _partIva="")const;
		void checkAvvisoGlobal(string _valTarga)const;
		//Metodi appoggio usate esclusivamente da altri metodi
		bool searchAuto(string _valTarga)const;
		set<TipoVeicolo>::iterator searchTipoVeicolo(Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag);
};

#endif

