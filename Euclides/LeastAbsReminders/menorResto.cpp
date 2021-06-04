#include <iostream>
#include <stdlib.h>
#include <NTL/ZZ.h>
#include <NTL/RR.h>
using namespace NTL;
using namespace std;

void Menor_resto(RR a, RR b){
    RR r; r=1;
    ZZ rZZ,aZZ,bZZ;
	RR aux; aux=0.5;

	while (r>0)
	{
		r=a/b+aux;
		conv(rZZ,r); conv(aZZ,a); conv(bZZ,b);
		rZZ=aZZ-(bZZ*(rZZ));
		rZZ=abs(rZZ);
		aZZ=bZZ;
		bZZ=abs(rZZ);
		conv(r,rZZ); conv(a,aZZ); conv(b,bZZ);
	}
	cout<<"\nel mcd de menor resto es: "<<a<<endl;
	}

int main (){
	RR a; a=542312;
	RR b; b=442321;

	Menor_resto(a,b);
}

