#include "data.h"


Data::Data(int _g,int _m ,int _a){
	giorno=_g;
	mese=_m;
	anno=_a;
}

ostream& operator <<(ostream& os,const Data &d){
	return os<<d.giorno<<":"<<d.mese<<":"<<d.anno;
}
