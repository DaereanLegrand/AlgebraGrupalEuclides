#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;

/*ZZ mimodulo(ZZ x, ZZ y)
{
    ZZ div; div = x / y;
    ZZ modulo; modulo = -(div * y) + x;
    if (modulo < 0)
        modulo += y;
    return modulo;
}*/

ZZ mod(ZZ a, ZZ b)
{
    ZZ r;
    r = a - b * (a / b);
    r = r + (r < 0) * b;
    return r;
}

ZZ potencia(ZZ x, ZZ y)
{
    ZZ counter;counter = 0;
    ZZ result;result = x;
    if (y == 0) {
        return ZZ(1);
    }
    else if (y == ZZ(1)) {
        return x;
    }
    else if (y == -1) {
        return y / x;
    }
    while (counter != y - 1) {
        result = result * x;
        counter++;
    }
    return result;
}

std::vector<ZZ>extendedbinaryalgorithm(ZZ x, ZZ y) {
    ZZ U,V,A,B,C,D,R,a,b,G; U = x; V = y; A = 1; B = 0; C = 0; D = 1; G=0;
    std::vector<ZZ>resultado;
    //Sacando factor comun de 2 a ambas variables
    while (true) {
        if (mod(U, ZZ(2)) == 0 && mod(V, ZZ(2)) == 0) {
            U = U / 2;
            V = V / 2;
            G++;
        }
        else {
            break;
        }

    }
    while (U != V) {
        if (mod(U, ZZ(2)) == 1) {
            if (U > V) {
                U = U - V;
                A = A - B;
                C = C - D;
            }
            else {
                V = V - U;
                B = B - A;
                D = D - C;
            }
        }
        else {
            U = U / 2;
            if (mod(A, ZZ(2)) == 0 and mod(B, ZZ(2)) == 0) {
                A = A / 2;
                C = C / 2;
            }
            else {
                A = (A + y) / 2;
                C = (C - x) / 2;
            }
        }
    }
    a = A;
    b = C;
    resultado.push_back(U*potencia(ZZ(2),G));
    resultado.push_back(a);
    resultado.push_back(b);
    return resultado;
}

void printvector(std::vector<ZZ>a) {
    for (int i = 0; i < a.size(); i++) {
        //std::cout << "\nExtended binary: " << a[i];
    }
}

int main()
{
    ZZ a,b;
    a = conv<ZZ>("113961491159425124522547710339601516414581636984912436254300859090699424230641");
	b = conv<ZZ>("83825486427085367934112210589772991484453445136409752382569536656995452034661");
    printvector(extendedbinaryalgorithm(a,b));
}
