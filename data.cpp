#include "data.h"


Data::Data(){
	time_t data;
	tm *dataInfo;
	data=time(NULL); //ottiene l'ora odierna
	dataInfo=localtime(&data); 
	giorno=tm_mday;
	mese=tm_mon;
	anno=tm_year;
}
Data::Data(int _g,int _m ,int _a){
	giorno=_g;
	mese=_m;
	anno=_a;
}
void Data::StampaData()const{
	cout<<giorno<<"/"<<mese<<"/"<<anno;
}
