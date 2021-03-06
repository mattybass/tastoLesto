#ifndef __DATA_H__
#define __DATA_H__

#include <iostream>
#include <ctime>

using namespace std; 

class Data{
	private:
	   int giorno;
	   int mese;
	   int anno;
	public:
	   Data();//iniaializza un oggetto data contenente la data di oggi
	   Data(int _g,int _m ,int _a);
	   friend bool operator <(Data const& d1, Data const& d2);
	   friend ostream& operator <<(ostream& os, const Data& _data);
};

ostream& operator << (ostream& os, const Data& _data);
bool operator<(Data const& d1, Data const& d2);

#endif
