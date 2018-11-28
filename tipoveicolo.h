#ifndef __TIPOVEICOLO_H__
#define __TIPOVEICOLO_H__
#include "sicurezza.h"
using namespace std;
typedef enum {MOTO,AUTO,CAMION,CAMPER}Tipo; //creo un enum che contiene tutti i tipi di veicolo possibili

class TipoVeicolo{
	private:
		Tipo tipo;
		string marca;
		string modello;
		int cilindrata;
		int kw;
		int catEuro;
		Sicurezza infosic; 
	public:
		TipoVeicolo(Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag);
		int const getKw(); //non so perche non mi fa usare il const dopo getkw();
		int const getCatEuro();	
		friend ostream& operator<<(ostream& os,const TipoVeicolo & v);
		friend bool operator<(const TipoVeicolo& _t, const TipoVeicolo& _t2);
		};
void test_tipoveicolo();
bool operator<(const TipoVeicolo& _t, const TipoVeicolo& _t2);
ostream& operator<<(ostream& os,const TipoVeicolo & v);
#endif
