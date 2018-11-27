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
//		Automobile automobile;
//		Proprietario proprietario;
		Data dataImmatricolazione;
	public:
		Veicolo(string _targa,int _g,int _m,int _a);
		void addBollo(int _g,int _m,int _a);
		void stampaBollo();
		void addAssicurazione(string _compagnia,int _g,int _m,int _a,int _durata);
		void addFurto(int _g, int _m, int _a, string _note, string _luogo);
		void addRevisione(int _g, int _m, int _a,int _kmRilevati);

};
void test_veicolo();

#endif
