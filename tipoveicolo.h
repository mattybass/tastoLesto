#ifndef __TIPOVEICOLO_H__
#define __TIPOVEICOLO_H__
using namespace std;
typedef enum {MOTO,AUTO,CAMION,CAMPER}Tipo; //creo un enum che contiene tutti i tipi di veicolo

class TipoVeicolo{
	private:
		int id;
		Tipo tipo;
		string marca;
		string modello;
		int cilindrata;
		int kw;
		int catEuro;
		//Sicurezza infosic; //da decommentare quando si aggiunge la classe sicurezza
	public:
		TipoVeicolo(Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro){
			
		}
};
#endif
