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
}

int main (){
	ZZ a;
	ZZ b;
	a = conv<ZZ>(38783);
	b = conv<ZZ>(38299);

	Menor_resto(a,b);
}
