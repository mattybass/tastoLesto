#ifndef __VEICOLO_H__
#define __VEICOLO_H__

#include <list>
#include <string>
#include "bollo.h"
#include "revisione.h"
#include "furto.h"
#include "assicurazione.h"
#include "data.h"

class Veicolo{
	private:
		string targa;
		list <Bollo> listaBollo;
		list <Furto> listaFurto;
		list <Assicurazione> listaAssicurazione;
		list <Revisione> listaRevisione;
		Data dataImmatricolazione;
	public:
		Veicolo(string _targa,int _g,int _m,int _a);
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
void test_veicolo();

#endif
