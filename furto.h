#ifndef __FURTO_H__
#define __FURTO_H__

#include "data.h"

using namespace std;

class Furto{
	private:
		Data dataDenuncia;
		string luogoDenuncia;
		string noteDenuncia;
		bool statoDenuncia;
	public:
		Furto(int _g, int _m, int _a, string _luogo, string _note);
		friend ostream& operator<<(ostream& os, const Furto &f);	
		bool get_statoDenuncia()const;
		void disattivaDenuncia();
};
ostream& operator<<(ostream& os, const Furto &f);

#endif

