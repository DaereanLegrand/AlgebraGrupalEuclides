#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sstream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ modulo (ZZ a,ZZ n, char val)
{
	//a = q*n + r  //0 =< r < n
	ZZ q, r;

	if (r<0)
	{
		q = q-1;
		r = a -(a / n) * n;
	}
	else
	{
		q = a / n;
		r = a - (q * n);
	}
	if (val=='q')
    {
        return q;
    }
    else if (val == 'r')
    {
        return r;
    }
    return r;
}
ZZ binario (ZZ a, ZZ b)
{
    ZZ aux;
    while (a>0)
	{
		ZZ div;
		div = 2;
        if(modulo(a,div,'r')==0 && modulo(b,div,'r')==0)
		{
			a=a/2;
			b=b/2;
		}
		else if(modulo(a,div,'r')==0 && modulo(b,div,'r')==1)
		{
			a=a/2;
		}
		else if(modulo(a,div,'r')==1 && modulo(b,div,'r')==0)
		{
			b=b/2;
		}
		else if (modulo(a,div,'r')==1 && modulo(b,div,'r')==1)
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
	a = conv<ZZ>("38783");
	b = conv<ZZ>("38299");
}
