#include "data.h"


Data::Data(){
	time_t data = time(0);//data salvata in data
	tm* tempo = localtime(&data);//inizializza struttura tm
	giorno=tempo->tm_mday;
	mese=tempo->tm_mon+1;
	anno=tempo->tm_year+1900;
}

Data::Data(int _g,int _m ,int _a){
	giorno=_g;
	mese=_m;
	anno=_a;
}

bool operator <(Data const& d1, Data const& d2){
	if(d1.anno!=d2.anno)
		return (d1.anno<d2.anno);
	else{
		if(d1.mese!=d2.mese)
			return (d1.mese<d2.mese);
		else
			return(d1.giorno<d2.giorno);
	}
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

void test_data(){
	Data d;
	cout<<endl<<"DATA ODIERNA: "<<d;
	Data d2(12,4,2900);
	cout<<endl<<(d2<d);
}

