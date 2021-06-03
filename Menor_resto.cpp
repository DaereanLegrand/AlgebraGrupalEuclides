#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;

ZZ Menor_resto(ZZ a, ZZ b){
    ZZ r; r=1;
	ZZ aux; aux=0.5;

	while (r>0)
	{
		r=a/b+aux;
		r=a-(b*(r));
		r=abs(r);
		a=b;
		b=abs(r);
	}
	cout<<"\nel mcd de menor resto es: "<<a<<endl;
	}

int main (){
	ZZ a; a=842780;
	ZZ b; b=253013;

	Menor_resto(a,b);
}
