#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sstream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ b)
{
    ZZ r;
    r = a - b * (a / b);
    r = r + (r < 0) * b;
    return r;
}
ZZ binario (ZZ a, ZZ b)
{
    ZZ aux;
    while (a>0)
	{
		ZZ div;
		div = 2;
        if(modulo(a,div)==0 && modulo(b,div)==0)
		{
			a=a/2;
			b=b/2;
		}
		else if(modulo(a,div)==0 && modulo(b,div)==1)
		{
			a=a/2;
		}
		else if(modulo(a,div)==1 && modulo(b,div)==0)
		{
			b=b/2;
		}
		else if (modulo(a,div)==1 && modulo(b,div)==1)
		{
			aux=b;
			if(a<b)
			{
				b=a;
			}
			if(b<a)
			{
				b=b;
			}
			a=abs((a-aux)/2);
		}
		//cout<<"a: "<<a<<endl;
        //cout<<"b: "<<b<<endl;
	}
	return b;
}

int main(){
	ZZ a, b;
	a = conv<ZZ>("113961491159425124522547710339601516414581636984912436254300859090699424230641");
	b = conv<ZZ>("83825486427085367934112210589772991484453445136409752382569536656995452034661");
	cout<<binario(a,b);
}
