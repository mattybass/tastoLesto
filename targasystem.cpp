#include "targasystem.h"
TargaSystem::TargaSystem():versione("1.0"){
	
}

ostream& operator<<(ostream& os, TargaSystem& t){
	os<<"Versione del programma: "<<t.versione<<endl;
	return os;
}

void TargaSystem::checkAvvisoPrivati(string _valTarga,string _codFisc,string _partIva)const{
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!="")//il veicolo appartiene ad un privato!
			{
				map<string,list<Veicolo> >::const_iterator iter;
				map<string,list<Veicolo> >::const_iterator temp;
				temp=mapPrivati.end();
				for(iter=mapPrivati.begin();iter!=mapPrivati.end();++iter){
					if (iter->first==_codFisc)
						temp=iter; //ho trovato la persona nel map
				}
				if(temp!=mapPrivati.end()){
					list<Veicolo>::const_iterator liter;
					list<Veicolo>::const_iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end()))//vuol dire che ho trovato la vettura
					(*temp2).check();
					else
						cout<<"Esiste la persona, ma non e' proprietaria di questo veicolo!"<<endl;
				}
				else 
					cout<<"Non esiste questa persona come proprietario di veicoli!"<<endl;
			}
			if(_partIva!="")//il veicolo appartiene ad un azienda!
			{
				map<string,list<Veicolo> >::const_iterator iter;
				map<string,list<Veicolo> >::const_iterator temp;
				temp=mapPrivati.end();
				for(iter=mapAziende.begin();iter!=mapAziende.end();++iter){
					if (iter->first==_partIva)
						temp=iter; //ho trovato l'azienda nel map
				}
				if(temp!=mapAziende.end()){
					list<Veicolo>::const_iterator liter;
					list<Veicolo>::const_iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end())){//vuol dire che ho trovato la vettura
					(*temp2).check();
					}
					else
						cout<<"Esiste l'azienda, ma non e' proprietaria di questa vettura!"<<endl;
				}
				else 
				cout<<"Non esiste questa azienda come proprietaria di veicoli!"<<endl;
		    }
		}
	}
}

void TargaSystem::stampaAuto(string _valTarga){
	map<string,list<Veicolo> >::iterator iter;
	map<string,list<Veicolo> >::iterator temp2;
	list<Veicolo>::iterator liter;
	list<Veicolo>::iterator temp;
	
	//temp=(iter->second).end();
	
	temp2=mapPrivati.end();
//	iter=mapPrivati.begin();
/*	while(iter!=mapPrivati.end() || temp2!=mapPrivati.end()){
		while
		
	}*/
for(iter=mapPrivati.begin();iter!=mapPrivati.end();iter++){
		temp=(iter->second).end();
		//temp2=mapPrivati.end();
		cout<<"A";
		for(liter=(iter->second).begin();liter!=(iter->second).end();liter++){
			cout<<"B";
			if((*liter).getTarga()==_valTarga){
				temp=liter;
				cout<<"C";
				break;
			}
		}
		if(temp!=(iter->second).end()){
			cout<<"D";
			temp2=iter;
			break;
		}
	}
	if(temp2!=mapPrivati.end()){ //significa che ho trovato l'auto nella mappa di privato - list<veicolo>
		cout<<"E";
		cout<<*temp; //adesso devo stampare l'automobile collegata
	}
	else{
		cout<<"5";
		temp2=mapAziende.end();
		
		for(iter=mapAziende.begin();iter!=mapAziende.end();++iter){
			temp=(iter->second).end();
			cout<<"6";
			for(liter=(iter->second).begin();liter!=(iter->second).end();++liter){
				if((*liter).getTarga()==_valTarga){
					temp=liter;
				}
			}	
			if(temp!=(iter->second).end()){
				cout<<"7";
				temp2=iter;						
			}
		}
		if(temp2!=mapAziende.end()){ //significa che ho trovato l'auto nella mappa di azienda - list<veicolo>
			cout<<"8";
			cout<<*temp; //adesso devo stampare l'automobile collegata //qua c'è l'errore
		}
		else //non ho trovato la vettura!
			cout<<"Non ï¿½ stata trovata alcuna vettura con questa targa!"<<endl;
	}
	
}
//QUESTE DUE FUNZIONI SERVONO PER POPOLARE LE MAP DI PROPRIETARI (PRIVATI O AZIENDE)
void TargaSystem::addPropPrivati(string _nome,string _cognome,string _codFiscale,string _luogoNascita,string _provincia, string _com, string _via, string _cap, int _nCivico){
	mapPropPrivati.insert(pair<string,Privato> (_codFiscale,Privato(_nome,_cognome,_codFiscale,_luogoNascita,_provincia,_com,_via,_cap,_nCivico)));
}

void TargaSystem::addPropAziende(string _nomeA,string _pIva,string _provincia, string _com, string _via, string _cap, int _nCivico){
	mapPropAziende.insert(pair<string,Azienda> (_pIva,Azienda(_nomeA,_pIva,_provincia,_com,_via,_cap,_nCivico)));
}

void TargaSystem::stampaPropAziende()const{
	map<string,Azienda>::const_iterator miter;
	for(miter=mapPropAziende.begin();miter!=mapPropAziende.end();miter++){
		cout<<(miter->first)<<endl;
		cout<<(miter->second)<<endl;
		cout<<endl<<"-----------------------"<<endl;
	}	
}

void TargaSystem::stampaPropPrivati()const{
	map<string,Privato>::const_iterator miter;
	for(miter=mapPropPrivati.begin();miter!=mapPropPrivati.end();miter++){
		cout<<(miter->first)<<endl;
		cout<<(miter->second)<<endl;
		cout<<"-----------------------"<<endl;
	}	
}

void TargaSystem::addPrivati(string _codFiscale,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag){
	map<string,list<Veicolo> >::iterator miter;
	list<Veicolo> listaV;
	set<TipoVeicolo>::iterator iter;
	miter=mapPrivati.find(_codFiscale);
	iter=searchTipoVeicolo(_tipo,_marca,_modello,_cilindrata,_kw,_catEuro,_euroNcap,_nAirbag);
	if(miter!=mapPrivati.end()){
		(miter->second).push_front(Veicolo(_targa,iter,_g,_m,_a));
	}
	else{
		listaV.push_front(Veicolo(_targa,iter,_g,_m,_a));
		mapPrivati.insert(make_pair(_codFiscale,listaV));
	}
}

void TargaSystem::addAziende(string _pIva,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag){
	map<string,list<Veicolo> >::iterator miter;
	list<Veicolo> listaV;
	set<TipoVeicolo>::iterator iter;
	miter=mapAziende.find(_pIva);
	iter=searchTipoVeicolo(_tipo,_marca,_modello,_cilindrata,_kw,_catEuro,_euroNcap,_nAirbag);
	if(miter!=mapAziende.end()){
		(miter->second).push_front(Veicolo(_targa,iter,_g,_m,_a));
	}
	else{
		listaV.push_front(Veicolo(_targa,iter,_g,_m,_a));
		mapAziende.insert(make_pair(_pIva,listaV));
	}
}


set<TipoVeicolo>::iterator TargaSystem::searchTipoVeicolo(Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag){
	set<TipoVeicolo>::const_iterator iter;
	iter=setTipoVeicolo.find(TipoVeicolo(_tipo,_marca,_modello,_cilindrata,_kw,_catEuro,_euroNcap,_nAirbag));
	if(iter!=setTipoVeicolo.end()){
		return iter;
	}
	else{
		TipoVeicolo v(_tipo,_marca,_modello,_cilindrata,_kw,_catEuro,_euroNcap,_nAirbag);
		setTipoVeicolo.insert(v);
		iter=setTipoVeicolo.find(TipoVeicolo(_tipo,_marca,_modello,_cilindrata,_kw,_catEuro,_euroNcap,_nAirbag));
		return iter;
	}
}

void test_targasystem(){
	TargaSystem t;
	t.addPrivati("MTTDNL98A30L378H","DN987EE",30,1,2018,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("MTTDNL98A30L378H","CS429PN",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("AAAA","TE746TT",20,1,2005,MOTO,"Kawasakj","Ninja",1500,50,4,5,0);
	t.addPrivati("bbbb","DD987DD",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("bbbb","RR567RR",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("bbbb","TT565TT",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	cout<<endl;
	t.stampaAuto("primo");
	cout<<endl;
	t.stampaAuto("CS429PN");
	cout<<endl;
	t.stampaAuto("DD987DD");
	cout<<endl;
	t.stampaAuto("RR567RR");
	cout<<endl;
	t.stampaAuto("TT565TT");		
	cout<<endl;	
	t.stampaAuto("DN987EE");
	cout<<endl;	
	t.stampaAuto("TE746TT");
	


}



