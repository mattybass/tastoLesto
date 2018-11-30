#ifndef __REVISIONE_H__
#define __REVISIONE_H__

#include "data.h"

using namespace std;

class Revisione{
	private:
		Data dataScadenzaR;
		Data dataInizioR;
		int kmRilevati;
	public:
		Revisione(int _g, int _m, int _a,int _kmRilevati,bool check);
		friend ostream& operator <<(ostream& os,const Revisione& _r);
		Data get_scadenza()const;
};
ostream& operator <<(ostream& os,const Revisione& _r);

#endif
