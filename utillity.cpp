#include "utility.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

Utility::Utility(){
	char c;
	char comune[50];
	char codice[5];

	ifstream myfile("belfiore.txt");
	int k=0;
	if (myfile.is_open()){
		int cont=0;
		int i=0;
		int j=0;
		while(myfile.get(c)){
			if(cont==0){
				if(c!=';'){
					comune[i]=c;
					i++;					
				}
			}
			if(cont==1){
				if(c!='\n'){
					codice[j]=c;
					j++;					
				}
			}
			if(cont==1 && c=='\n'){
				comune[i]='\0';
				codice[j]='\0';
				cont=0;
				i=0;
				j=0;
				string com(comune);
				string cod(codice);
				mapBelfiore.insert(pair<string,string> (com,cod));
		//		cout<<com<<" "<<cod<<endl;	
			}
			if(c==';')
				cont++;	
		}	
	}
	myfile.close();

}	


string Utility::getLuogo(string _codiceCatastale)const{
	map<string,string>::const_iterator iter;
	iter=mapBelfiore.find(_codiceCatastale);
	return iter->second;
}

void test_utility(){
	Utility u;
	cout<<u.getLuogo("L378");
//	u.stampa();
}

int convertiStringa(string stringa, int inizio, int nCaratteri){
	string sEstratta=stringa.substr(inizio,nCaratteri);
	stringstream ss(sEstratta);
	int i;
  	ss >> i;
  	
  	return i;
}

void Utility::stampa()const{
map<string,string>::const_iterator iter;
for(iter=mapBelfiore.begin();iter!=mapBelfiore.end();iter++){
	cout<<iter->first<<", "<<iter->second<<endl;
}
}

