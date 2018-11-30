#include "utility.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

Utility::Utility(){
	mapBelfiore.insert(pair<string,string> (string("L378"),string("Trento")));
	mapBelfiore.insert(pair<string,string> (string("H330"),string("Riva del Garda")));
	mapBelfiore.insert(pair<string,string> (string("A001"),string("Abano Terme")));
	mapBelfiore.insert(pair<string,string> (string("A002"),string("Abbadia Cerreto")));
}

string Utility::getLuogo(string _codiceCatastale)const{
	map<string,string>::const_iterator iter;
	iter=mapBelfiore.find(_codiceCatastale);
	return iter->second;
}

void test_utility(){
	Utility u;
	cout<<u.getLuogo("L378");
}

int convertiStringa(string stringa, int inizio, int nCaratteri){
	string sEstratta=stringa.substr(inizio,nCaratteri);
	stringstream ss(sEstratta);
	int i;
  	ss >> i;
  	
  	return i;
}

