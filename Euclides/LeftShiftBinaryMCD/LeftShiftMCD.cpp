#include <iostream>
#include <vector>
#include<NTL/ZZ.h>
using namespace NTL;
using namespace std;

ZZ potencia(ZZ x, ZZ y)
{
    ZZ counter; counter = 0;
    ZZ result; result = x;
    if (y == 0) {
        return ZZ(1);
    }
    else if (y == 1) {
        return x;
    }
    else if (y==-1){
        return y/x;
    }
    while (counter != y - 1) {
        result = result * x;
        counter++;
    }
    return result;
}

ZZ AlgoritmoLSBGCD(ZZ a, ZZ b) {
    while (b != 0) {
        ZZ intercambio, s, r,minA,minB;
        a = abs(a); b = abs(b);
        while (b != 0) {
            s = 0;
            while ((b * potencia(ZZ(2),s)) <= a) {
                s++;
            }
            s--;
            minA = a-b*potencia(ZZ(2),s); minB = (b * potencia(ZZ(2),(s + ZZ(1))) - a);
            r = minA;
            if (minA > minB) {
                r = minB;
            }
            a = b; b = r;
            if (a < b) {
                intercambio = a; a = b; b = intercambio;
            }
        }
    }
    return a;
}

int main()
{
    ZZ a,b;
    a = conv<ZZ>("38783");
	b = conv<ZZ>("38299");
    ZZ c; c=AlgoritmoLSBGCD(a,b);
}
