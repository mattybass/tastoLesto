#ifndef __SICUREZZA_H__
#define __SICUREZZA_H__

#include <iostream>

using namespace std;

class Sicurezza{
	private:
		int euroNcap;
		int nAirbag;
	public:
		Sicurezza(int _na, int _ncap);
		int geteuroNcap()const;
		int getnAirbag()const;
		friend ostream& operator<<(ostream& os, const Sicurezza& s);
};
ostream& operator<<(ostream& os, const Sicurezza& s);
#endif
