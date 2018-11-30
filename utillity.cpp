#include "utility.h"

#include <iomanip>
#include <fstream>
#include <sstream>

Utility::Utility(){
	char c;
	char comune[50];
	char codice[5];
	ifstream myfile("tastoLesto/belfiore.txt");
	int k=0;
	while(!myfile.eof()){
		bool check=0;
		int i=0;
		int j=0;
		while(myfile.get(c)){
			if(check==0){
				if(c!=';'){
					comune[i]=c;
					i++;					
				}
				else
					check=1;
			}
			else{
				if(c!='\n'){
					codice[j]=c;
					j++;					
				}
				else{
					comune[i]='\0';
					codice[j]='\0';
					check=0;
					i=0;
					j=0;
					string com(comune);
					string cod(codice);
					mapBelfiore.insert(pair<string,string> (cod,com));					
				}
			}
		}	
	}
	myfile.close();
}	

string Utility::getLuogo(string _codiceCatastale)const{
	map<string,string>::const_iterator iter;
	iter=mapBelfiore.find(_codiceCatastale);
	if(iter!=mapBelfiore.end())
		return iter->second;
	else
		return "NON TROVATO!";
}

int convertiStringa(string stringa, int inizio, int nCaratteri){
	string sEstratta=stringa.substr(inizio,nCaratteri);
	stringstream ss(sEstratta);
	int i;
  	ss >> i;
  	
  	return i;
}

