#ifndef __data_h__
#define __data_h__

#include <cstdlib>
#include <iostream>

using namespace std; 

class Data{
	private:
	   int giorno,mese,anno;
	public:
	   Data(int _g,int _m ,int _a);
	   friend ostream& operator <<(ostream& os,const Data &d);
	
};
ostream& operator <<(ostream& os,const Data &d);

#endif
