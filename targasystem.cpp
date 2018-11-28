#include "targasystem.h"
TargaSystem::TargaSystem():versione("1.0"){
	
}


ostream& operator<<(ostream& os, TargaSystem& t){
	os<<"Versione del programma: "<<t.versione<<endl;
	return os;
}

void test_targasystem(){
	TargaSystem t;
	cout<<t;
	
}
