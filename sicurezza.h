#ifndef __SICUREZZA_H__
#define __SICUREZZA_H__
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Sicurezza{
	private:
		int euroNcap;
		int nAirbag;
	public:
		Sicurezza();
		Sicurezza(int _na, int _ncap);
		void stampa()const;
};

void test_sicurezza();
#endif