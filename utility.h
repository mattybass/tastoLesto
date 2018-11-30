#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

class Utility{
	private:
		map<string,string> mapBelfiore;
	public:
		Utility();
	//	void popolaBelfiore(string _stringa);
		string getLuogo(string _codiceCatastale)const;
		void stampa()const;
	
};
#endif

//string luogo_codiceF(string _codiceCatastale);
void test_utility();
int convertiStringa(string stringa, int inizio, int nCaratteri);
