#include "targasystem.h"

TargaSystem::TargaSystem():versione("1.0"){
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

void TargaSystem::stampaAuto(string _valTarga)const{//FUNZIONE DI STAMPA TARGA IN TUTTO IL DATABASE
	map<string,list<Veicolo> >::const_iterator iter;
	map<string,list<Veicolo> >::const_iterator temp2;
	list<Veicolo>::const_iterator liter;
	list<Veicolo>::const_iterator temp;
	
	temp2=mapPrivati.end();
	iter=mapPrivati.begin();
	while(iter!=mapPrivati.end()&&temp2==mapPrivati.end()){
		temp=(iter->second).end();
		liter=(iter->second).begin();
		while(liter!=(iter->second).end()&&temp==(iter->second).end()){
			if((*liter).getTarga()==_valTarga){
				temp=liter;
			}
			liter++;
		}
		if(temp!=(iter->second).end()){
			temp2=iter;
		}
		iter++;
	}
	if(temp2!=mapPrivati.end())
		cout<<*temp;
	else{
		temp2=mapAziende.end();
		iter=mapAziende.begin();
		while(iter!=mapAziende.end()&&temp2==mapAziende.end()){
			temp=(iter->second).end();
			liter=(iter->second).begin();
			while(liter!=(iter->second).end()&&temp==(iter->second).end()){
				if((*liter).getTarga()==_valTarga){
					temp=liter;
				}
				liter++;
			}
			if(temp!=(iter->second).end()){
				temp2=iter;
			}
			iter++;
		}
		if(temp2!=mapAziende.end())
			cout<<*temp;
		else
			cout<<"Auto non presente!"<<endl;
			
		}
}

bool TargaSystem::searchAuto(string _valTarga)const{//CONTROLLA SE LA TARGA E' GIA' PRESENTE IN DATABASE
	map<string,list<Veicolo> >::const_iterator iter;
	map<string,list<Veicolo> >::const_iterator temp2;
	list<Veicolo>::const_iterator liter;
	list<Veicolo>::const_iterator temp;
	
	temp2=mapPrivati.end();
	iter=mapPrivati.begin();
	while(iter!=mapPrivati.end()&&temp2==mapPrivati.end()){
		temp=(iter->second).end();
		liter=(iter->second).begin();
		while(liter!=(iter->second).end()&&temp==(iter->second).end()){
			if((*liter).getTarga()==_valTarga){
				temp=liter;
			}
			liter++;
		}
		if(temp!=(iter->second).end()){
			temp2=iter;
		}
		iter++;
	}
	if(temp2!=mapPrivati.end())
		return true;
	else{
		temp2=mapAziende.end();
		iter=mapAziende.begin();
		while(iter!=mapAziende.end()&&temp2==mapAziende.end()){
			temp=(iter->second).end();
			liter=(iter->second).begin();
			while(liter!=(iter->second).end()&&temp==(iter->second).end()){
				if((*liter).getTarga()==_valTarga){
					temp=liter;
				}
				liter++;
			}
			if(temp!=(iter->second).end()){
				temp2=iter;
			}
			iter++;
		}
		if(temp2!=mapAziende.end())
			return true;
		else
			return false;
			
		}
}

void TargaSystem::stampaProp(string _valTarga)const{
	map<string,list<Veicolo> >::const_iterator iter;
	map<string,list<Veicolo> >::const_iterator temp2;
	list<Veicolo>::const_iterator liter;
	list<Veicolo>::const_iterator temp;
	map<string,Privato>::const_iterator iterPrivato;
	map<string,Azienda>::const_iterator iterAzienda;
	
	temp2=mapPrivati.end();
	iter=mapPrivati.begin();
	while(iter!=mapPrivati.end()&&temp2==mapPrivati.end()){
		temp=(iter->second).end();
		liter=(iter->second).begin();
		while(liter!=(iter->second).end()&&temp==(iter->second).end()){
			if((*liter).getTarga()==_valTarga){
				temp=liter;
			}
			liter++;
		}
		if(temp!=(iter->second).end()){
			temp2=iter;
		}
		iter++;
	}
	if(temp2!=mapPrivati.end()){
		string search=temp2->first;
		iterPrivato=mapPropPrivati.find(search);
		if(iterPrivato!=mapPropPrivati.end()){
			(iterPrivato->second).stampa();
			//cout<<*(iterPrivato->second) NON FUNZIONA! PERCHE'?
		}
	}	
	else{
		temp2=mapAziende.end();
		iter=mapAziende.begin();
		while(iter!=mapAziende.end()&&temp2==mapAziende.end()){
			temp=(iter->second).end();
			liter=(iter->second).begin();
			while(liter!=(iter->second).end()&&temp==(iter->second).end()){
				if((*liter).getTarga()==_valTarga){
					temp=liter;
				}
				liter++;
			}
			if(temp!=(iter->second).end()){
				temp2=iter;
			}
			iter++;
		}
		if(temp2!=mapAziende.end()){
			iterAzienda=mapPropAziende.find(temp2->first);
			if(iterAzienda!=mapPropAziende.end()){
				(iterAzienda->second).stampa();
				//cout<<*(iterAzienda->second) NON FUNZIONA! PERCHE'?
			}
		}
		else
			cout<<"Targa non trovata"<<endl;
		}
}

void TargaSystem::addPropPrivati(string _nome,string _cognome,string _codFiscale,string _provincia, string _com, string _via, string _cap, int _nCivico){
	mapPropPrivati.insert(pair<string,Privato> (_codFiscale,Privato(_nome,_cognome,_codFiscale,u.getLuogo(_codFiscale.substr(11,4)),_provincia,_com,_via,_cap,_nCivico)));
}

void TargaSystem::addPropAziende(string _nomeA,string _pIva,string _provincia, string _com, string _via, string _cap, int _nCivico){
	mapPropAziende.insert(pair<string,Azienda> (_pIva,Azienda(_nomeA,_pIva,_provincia,_com,_via,_cap,_nCivico)));
}

void TargaSystem::stampaPropAziende()const{
	cout<<"LISTA PROPRIETARI AZIENDE"<<endl;
	map<string,Azienda>::const_iterator miter;
	for(miter=mapPropAziende.begin();miter!=mapPropAziende.end();miter++){
		cout<<"-----------------------"<<endl;
		cout<<(miter->second)<<endl;
	}	
	cout<<endl<<endl;
}

void TargaSystem::stampaPropPrivati()const{
	cout<<"LISTA PROPRIETARI PRIVATI"<<endl;
	map<string,Privato>::const_iterator miter;
	for(miter=mapPropPrivati.begin();miter!=mapPropPrivati.end();miter++){
		cout<<"-----------------------"<<endl;
		cout<<(miter->second)<<endl;
	}	
	cout<<endl<<endl;
}

void TargaSystem::addPrivati(string _codFiscale,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag){
	if(searchAuto(_targa)==0){
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
	else
		cout<<_targa<<" ha gia' un proprietario"<<endl;
}

void TargaSystem::addAziende(string _pIva,string _targa,int _g,int _m,int _a,Tipo _tipo, string _marca, string _modello, int _cilindrata, int _kw, int _catEuro, int _euroNcap, int _nAirbag){
	if(searchAuto(_targa)==0){	
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
	else
		cout<<_targa<<" ha gia' un proprietario"<<endl;
}		

void TargaSystem::addBollo(string _valTarga,int _g,int _m,int _a, string _codFisc,string _partIva){
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapPrivati.begin();iter!=mapPrivati.end();++iter){
					if (iter->first==_codFisc)
						temp=iter; //ho trovato la persona nel map
				}
				if(temp!=mapPrivati.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end()))//vuol dire che ho trovato la vettura
					(*temp2).addBollo(_g,_m,_a);
					else
						cout<<"Esiste la persona, ma non e' proprietaria di questo veicolo!"<<endl;
				}
				else 
					cout<<"Non esiste questa persona come proprietario di veicoli!"<<endl;
			}
			if(_partIva!="")//il veicolo appartiene ad un azienda!
			{
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapAziende.begin();iter!=mapAziende.end();++iter){
					if (iter->first==_partIva)
						temp=iter; //ho trovato l'azienda nel map
				}
				if(temp!=mapAziende.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end())){//vuol dire che ho trovato la vettura
					(*temp2).addBollo(_g,_m,_a);
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

void TargaSystem::addFurto(string _valTarga,int _g,int _m,int _a, string _luogoDenuncia, string _noteDenuncia, string _codFisc,string _partIva){
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapPrivati.begin();iter!=mapPrivati.end();++iter){
					if (iter->first==_codFisc)
						temp=iter; //ho trovato la persona nel map
				}
				if(temp!=mapPrivati.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end()))//vuol dire che ho trovato la vettura
					(*temp2).addFurto(_g,_m,_a,_noteDenuncia,_luogoDenuncia);
					else
						cout<<"Esiste la persona, ma non e' proprietaria di questo veicolo!"<<endl;
				}
				else 
					cout<<"Non esiste questa persona come proprietario di veicoli!"<<endl;
			}
			if(_partIva!="")//il veicolo appartiene ad un azienda!
			{
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapAziende.begin();iter!=mapAziende.end();++iter){
					if (iter->first==_partIva)
						temp=iter; //ho trovato l'azienda nel map
				}
				if(temp!=mapAziende.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end())){//vuol dire che ho trovato la vettura
					(*temp2).addFurto(_g,_m,_a,_noteDenuncia,_luogoDenuncia);
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

void TargaSystem::addAssicurazione(string _valTarga,int _g,int _m,int _a, int _anniDurata, string _compagnia, string _codFisc,string _partIva){
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapPrivati.begin();iter!=mapPrivati.end();++iter){
					if (iter->first==_codFisc)
						temp=iter; //ho trovato la persona nel map
				}
				if(temp!=mapPrivati.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end()))//vuol dire che ho trovato la vettura
					(*temp2).addAssicurazione(_compagnia,_g,_m,_a,_anniDurata);
					else
						cout<<"Esiste la persona, ma non e' proprietaria di questo veicolo!"<<endl;
				}
				else 
					cout<<"Non esiste questa persona come proprietario di veicoli!"<<endl;
			}
			if(_partIva!="")//il veicolo appartiene ad un azienda!
			{
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapAziende.begin();iter!=mapAziende.end();++iter){
					if (iter->first==_partIva)
						temp=iter; //ho trovato l'azienda nel map
				}
				if(temp!=mapAziende.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end())){//vuol dire che ho trovato la vettura
					(*temp2).addAssicurazione(_compagnia,_g,_m,_a,_anniDurata);
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

void TargaSystem::addRevisione(string _valTarga,int _g,int _m,int _a, int _kmRilevati, string _codFisc,string _partIva){
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapPrivati.begin();iter!=mapPrivati.end();++iter){
					if (iter->first==_codFisc)
						temp=iter; //ho trovato la persona nel map
				}
				if(temp!=mapPrivati.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end()))//vuol dire che ho trovato la vettura
					(*temp2).addRevisione(_g,_m,_a,_kmRilevati);
					else
						cout<<"Esiste la persona, ma non e' proprietaria di questo veicolo!"<<endl;
				}
				else 
					cout<<"Non esiste questa persona come proprietario di veicoli!"<<endl;
			}
			if(_partIva!="")//il veicolo appartiene ad un azienda!
			{
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapAziende.begin();iter!=mapAziende.end();++iter){
					if (iter->first==_partIva)
						temp=iter; //ho trovato l'azienda nel map
				}
				if(temp!=mapAziende.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end())){//vuol dire che ho trovato la vettura
					(*temp2).addRevisione(_g,_m,_a,_kmRilevati);
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

void TargaSystem::disattivaDenuncia(string _valTarga,string _codFisc,string _partIva){
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapPrivati.begin();iter!=mapPrivati.end();++iter){
					if (iter->first==_codFisc)
						temp=iter; //ho trovato la persona nel map
				}
				if(temp!=mapPrivati.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end()))//vuol dire che ho trovato la vettura
					(*temp2).disattivaDenuncia();
					else
						cout<<"Esiste la persona, ma non e' proprietaria di questo veicolo!"<<endl;
				}
				else 
					cout<<"Non esiste questa persona come proprietario di veicoli!"<<endl;
			}
			if(_partIva!="")//il veicolo appartiene ad un azienda!
			{
				map<string,list<Veicolo> >::iterator iter;
				map<string,list<Veicolo> >::iterator temp;
				temp=mapPrivati.end();
				for(iter=mapAziende.begin();iter!=mapAziende.end();++iter){
					if (iter->first==_partIva)
						temp=iter; //ho trovato l'azienda nel map
				}
				if(temp!=mapAziende.end()){
					list<Veicolo>::iterator liter;
					list<Veicolo>::iterator temp2;
					temp2=(temp->second.end());
					for(liter=temp->second.begin();liter!=temp->second.end();++liter){
						if((*liter).getTarga()==_valTarga)	
							temp2=liter;//ho trovato la vettura nella lista
					}
					if(temp2!=(temp->second.end())){//vuol dire che ho trovato la vettura
					(*temp2).disattivaDenuncia();
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

void TargaSystem::stampaBollo(string _valTarga,string _codFisc,string _partIva)const{
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
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
					(*temp2).stampaBollo();
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
					(*temp2).stampaBollo();
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
void TargaSystem::stampaFurto(string _valTarga,string _codFisc,string _partIva)const{
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
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
					(*temp2).stampaFurto();
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
					(*temp2).stampaFurto();
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
void TargaSystem::stampaAssicurazione(string _valTarga,string _codFisc,string _partIva)const{
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
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
					(*temp2).stampaAssicurazione();
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
					(*temp2).stampaAssicurazione();
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
void TargaSystem::checkAvvisoGlobal(string _valTarga)const{
	map<string,list<Veicolo> >::const_iterator iter;
	map<string,list<Veicolo> >::const_iterator temp2;
	list<Veicolo>::const_iterator liter;
	list<Veicolo>::const_iterator temp;
	
	temp2=mapPrivati.end();
	iter=mapPrivati.begin();
	while(iter!=mapPrivati.end()&&temp2==mapPrivati.end()){
		temp=(iter->second).end();
		liter=(iter->second).begin();
		while(liter!=(iter->second).end()&&temp==(iter->second).end()){
			if((*liter).getTarga()==_valTarga){
				temp=liter;
			}
			liter++;
		}
		if(temp!=(iter->second).end()){
			temp2=iter;
		}
		iter++;
	}
	if(temp2!=mapPrivati.end())
		(*temp).check();
	else{
		temp2=mapAziende.end();
		iter=mapAziende.begin();
		while(iter!=mapAziende.end()&&temp2==mapAziende.end()){
			temp=(iter->second).end();
			liter=(iter->second).begin();
			while(liter!=(iter->second).end()&&temp==(iter->second).end()){
				if((*liter).getTarga()==_valTarga){
					temp=liter;
				}
				liter++;
			}
			if(temp!=(iter->second).end()){
				temp2=iter;
			}
			iter++;
		}
		if(temp2!=mapAziende.end())
			(*temp).check();
		else
			cout<<"Auto non presente!"<<endl;
			
		}
}
void TargaSystem::stampaRevisione(string _valTarga,string _codFisc,string _partIva)const{
	if((_codFisc!="")&&(_partIva!="")){
		cout<<"Scegli, o codice fiscale o partita iva!"<<endl;
	}
	else{
		if((_codFisc=="")&&(_partIva=="")){
			cout<<"Inserisci il codice fiscale o la partita iva!"<<endl;
		}
		else{
			if(_codFisc!=""){//il veicolo appartiene ad un privato!
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
					(*temp2).stampaRevisione();
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
					(*temp2).stampaRevisione();
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
	t.addPrivati("MTTDNL98A30I830H","DN987EE",20,11,2013,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("MTTDNL98A30L378H","DN987EE",30,1,2018,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("MTTDNL98A30L378H","DD987DD",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("AAAA","TE746TT",20,1,2005,MOTO,"Kawasakj","Ninja",1500,50,4,5,0);
	t.addPrivati("bbbb","DD987DD",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("bbbb","RR567RR",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addPrivati("bbbb","TT565TT",20,1,2005,MOTO,"Kawasakj","Ninja",1000,50,4,5,0);
	t.addAziende("ziopino","YR747YE",20,1,2005,CAMPER,"Ford","Turistico",2000,50,1,4,0);
	t.addAziende("ziopino","UE876TT",20,1,2005,CAMPER,"Ford","Turistico",2000,50,1,4,0);
	t.addAziende("iaiaiaia","YH543FF",20,1,2005,CAMPER,"Ford","Turistico",2000,50,1,4,0);
	t.addAziende("qooqoqoqqo","UJ654GG",20,1,2005,CAMPER,"Ford","Turistico",2000,50,1,4,0);
	cout<<endl;
	t.checkAvvisoGlobal("DD987DD");
	cout<<endl;
	t.checkAvvisoGlobal("DIOPORCOOO");
	cout<<endl;
/*	t.stampaAuto("CS429PN");
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
	cout<<endl;	
	t.stampaAuto("YR747YE");
	cout<<endl;	
	t.stampaAuto("UE876TT");
	cout<<endl;	
	t.stampaAuto("YH543FF");
	cout<<endl;	
	t.stampaAuto("UJ654GG");
	cout<<endl;	*/
//	t.stampaAuto("mattydemocristiano");
	t.addPropPrivati("Daniele","Mattedi","MTTDNL98A30I830H","TN","Madruzzo","Roma","38076",23);
	t.addPropPrivati("Danilo","Mattedi","MTTDNL97A30Z356H","TN","Madruzzo","Roma","38076",23);
	t.addPropAziende("Roberti-programmatore","ziopino","TN","Vallelaghi","Roma","38070",1);
	t.addPropAziende("Roberti-programmatore","ziopero","TN","Vallelaghi","Roma","38070",1);
	t.stampaPropPrivati();
	t.stampaPropAziende();
	/*cout<<endl<<endl<<endl;
	t.stampaProp("DN987EE");
	cout<<endl<<endl<<endl;
//	t.stampaProp("YR747YE");
	//t.checkAvviso("DN987EE","MTTDNL98A30L378H");
	t.stampaFurto("DN987EE","MTTDNL98A30L378H"); //
	t.stampaAssicurazione("DN987EE","MTTDNL98A30L378H");//
	t.stampaRevisione("DN987EE","MTTDNL98A30L378H");//
	cout<<endl;
	t.addBollo("DN987EE",1,11,2018,"MTTDNL98A30L378H");
	t.addFurto("DN987EE",30,11,2018,"Calavino","ho stato io con lu trattore","MTTDNL98A30L378H");
	t.addRevisione("DN987EE",30,11,2018,25487,"MTTDNL98A30L378H");
	t.stampaFurto("DN987EE","MTTDNL98A30L378H");//
	t.stampaRevisione("DN987EE","MTTDNL98A30L378H");//
	
	cout<<endl<<endl;
	t.checkAvviso("DN987EE","MTTDNL98A30L378H");
	cout<<endl<<endl;
	t.disattivaDenuncia("DN987EE","MTTDNL98A30L378H");
	t.stampaFurto("DN987EE","MTTDNL98A30L378H");
	cout<<endl<<endl;
	t.checkAvviso("DN987EE","MTTDNL98A30L378H");
	
	
	
	*/
	


}



