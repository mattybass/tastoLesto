#include "tipoveicolo.h"

TipoVeicolo::TipoVeicolo(Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag):infosic(_nAirbag,_euroNcap){
	tipo=_tipo;
	marca=_marca;
	modello=_modello;
	cilindrata=_cilindrata;
	kw=_kw;
	catEuro=_catEuro;
}
int const TipoVeicolo::getKw(){
	return kw;
}
int const TipoVeicolo::getCatEuro(){
	return catEuro;
}
bool operator<(const TipoVeicolo& _t, const TipoVeicolo& _t2){
	if(_t.marca!=_t2.marca){
		return(_t.marca<_t2.marca);
	}
	else{
		if(_t.modello!=_t2.modello){
			return(_t.modello<_t2.modello);
		}
		else{
			if(_t.cilindrata!=_t2.cilindrata)
		}
	}
}
ostream& operator<<(ostream& os,TipoVeicolo const& v){
	 switch(v.tipo){
	 	case MOTO:
	 		os<<"Tipo veicolo: MOTO"<<endl;
	 		break;
	 	case AUTO:
	 		os<<"Tipo veicolo: AUTOMOBILE"<<endl;
	 		break;
	 	case CAMION:
	 		os<<"Tipo veicolo: CAMION"<<endl;
	 		break;
	 	case CAMPER:
	 		os<<"Tipo veicolo: CAMPER"<<endl;
	 		break;
	 	default:
	 		//è impossibile entrare nel default
	 		break;
	 }
	 os<<"Marca: "<<v.marca<<endl;
	 os<<"Modello: "<<v.modello<<endl;
	 os<<"Cilindrata: "<<v.cilindrata<<"cc"<<endl;
	 os<<"Kilowatt: "<<v.kw<<endl;
	 os<<"Categoria Euro: "<<v.catEuro<<endl<<endl;
	 os<<"Informazioni sulla sicurezza"<<endl;
	 os<<"Stelle euroNcap: "<<v.infosic.geteuroNcap()<<endl;
	 os<<"Numero airbag: "<<v.infosic.getnAirbag()<<endl;
	 return os;
}
void test_tipoveicolo(){
	TipoVeicolo a(MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	cout<<a;
	//questa non funziona il tipo di veicolo deve essere uno di quelli tra l'enum! TipoVeicolo b(Camper,"Kawasakj","Ninja",1000,50,4,5,0);
	//cout<<b;
}	
