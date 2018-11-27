#ifndef __DATA_H__
#define __DATA_H__
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std; 

class Data{
	private:
	   int giorno;
	   int mese;
	   int anno;
	public:
	   Data();
	   Data(int _g,int _m ,int _a);
	   friend bool operator <(Data const& d1, Data const& d2);
	   friend ostream& operator <<(ostream& os, const Data& _data);
};

ostream& operator << (ostream& os, const Data& _data);
bool operator<(Data const& d1, Data const& d2);
void test_data();

#endif
