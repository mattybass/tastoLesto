#include "data.h"


Data::Data(int _g,int _m ,int _a){
	giorno=_g;
	mese=_m;
	anno=_a;
}


ostream& operator << (ostream& os, const Data& _data){
    if(_data.giorno<10){
        os<<"0"<<_data.giorno<<"/";
    }else{
        os<<_data.giorno<<"/";
    }
    
    if(_data.mese<10){
        os<<"0"<<_data.mese<<"/";
    }else{
        os<<_data.mese<<"/";
    }
    
    os<<_data.anno;
    

    return os;
}

