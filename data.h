#ifndef __data_h__
#define __data_h__


#include <cstdlib>
#include <iostream>
#include <time.h> // per la data odierna 

using namespace std; 

class Data{
	private:
	   int giorno,mese,anno;
	public:
	   Data();
	   Data(int _g,int _m ,int _a);
	   void stampa()const;
	   friend ostream& operator <<(ostream& os,const Data &d);
	
};
ostream& operator <<(ostream& os,const Data &d);

#endif
