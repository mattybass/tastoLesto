#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <map>
#include <string>

using namespace std;

class Utility{
	private:
		map<string,string> mapBelfiore;
	public:
		Utility();
		string getLuogo(string _codiceCatastale)const;
	
};
int convertiStringa(string stringa, int inizio, int nCaratteri);

#endif

