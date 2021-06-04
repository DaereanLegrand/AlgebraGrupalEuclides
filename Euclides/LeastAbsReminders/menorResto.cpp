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
}

int main (){
	RR a;RR b;
	a = conv<RR>("113961491159425124522547710339601516414581636984912436254300859090699424230641");
	b = conv<RR>("83825486427085367934112210589772991484453445136409752382569536656995452034661");
	Menor_resto(a,b);
}

