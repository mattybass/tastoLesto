#ifndef __data_h__
#define __data_h__

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std; 

class Data{
	private:
	   int giorno,mese,anno;
	public:
	   Data();
	   Data(int _g,int _m ,int _a);
	   bool operator<(const Data &d1);
	   friend ostream& operator << (ostream& os, const Data& _data);
};
ostream& operator << (ostream& os, const Data& _data);

void test_data();
#endif
