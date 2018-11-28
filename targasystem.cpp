#include "targasystem.h"
TargaSystem::TargaSystem():versione("1.0"){
	
}


ostream& operator<<(ostream& os, TargaSystem& t){
	os<<"Versione del programma: "<<t.versione<<endl;
	return os;
}
void TargaSystem::checkAvviso(string _valTarga,string _codFisc,string _partIva)const{
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
						cout<<"Esiste la persona, ma non è proprietaria di questo veicolo!"<<endl;
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
						cout<<"Esiste l'azieda, ma non è proprietaria di questa vettura!"<<endl;
				}
				else 
				cout<<"Non esiste questa azienda come proprietaria di veicoli!"<<endl;
		    }
		}
	}
}
void TargaSystem::stampaAuto(string _valTarga)const{
	map<string, 
}
void test_targasystem(){
	TargaSystem t;
	cout<<t;
	t.checkAvviso("CY458KK","RRR");
	
}

