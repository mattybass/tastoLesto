#ifndef __VEICOLO_H__
#define __VEICOLO_H__
#include <list>
#include <set>
#include <string>

#include "tipoveicolo.h"
#include "bollo.h"
#include "revisione.h"
#include "furto.h"
#include "assicurazione.h"
#include "data.h"

using namespace std;

class Veicolo{
	private:
		string targa;
		list <Bollo> listaBollo;
		list <Furto> listaFurto;
		list <Assicurazione> listaAssicurazione;
		list <Revisione> listaRevisione;
		Data dataImmatricolazione;
		set<TipoVeicolo>::const_iterator tipoVeicoloCollegato;
	public:
		Veicolo(string _targa,set<TipoVeicolo>::iterator _tipoVeicoloCollegato,int _g,int _m,int _a);
		void addBollo(int _g,int _m,int _a);
		void addAssicurazione(string _compagnia,int _g,int _m,int _a,int _durata);
		void addFurto(int _g, int _m, int _a, string _note, string _luogo);
		void addRevisione(int _g, int _m, int _a,int _kmRilevati);
		
		void stampaBollo()const;
		void stampaFurto()const;
		void stampaAssicurazione()const;
		void stampaRevisione()const;

		bool checkBollo()const;
		bool checkAssicurazione()const;
		bool checkFurto()const;
		bool checkRevisione()const;
		void check()const;
		
		void disattivaDenuncia();
		string getTarga()const;
		friend ostream& operator<<(ostream& os, const Veicolo& _v);
		

};
ostream& operator<<(ostream& os, const Veicolo& _v);

#endif
