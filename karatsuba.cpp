#include <iostream>

using namespace std;

/**
 *Finds power 
 *@param x base number
 *@param y power
 *@return power of x by y
 */
long long findPower(long long x, long long y){
    if(y < 0)
        return -1;
    else if(y == 0)
        return 1;
    else if(y == 1)
        return x;    

    if(y % 2 == 0){
        return findPower(x, y/2)*findPower(x, y/2);
    }else{
        return findPower(x, (y-1)/2)*findPower(x, (y-1)/2)*x;
    }
}

/**
 *Karatsuba multiplication of two number with n digit 
 *
 *@param x first number
 *@param y second number
 *@param n digit count of x and y
 *@return multiplication result
 */
long long multiplyKaratsuba(long long x, long long y, long long n){
    if(n =1)
        return x*y;
    long long a,b,c,d;
    a=x/findPower(10, n/2);
    b=x%findPower(10, n/2);

    c=y/findPower(10, n/2);
    d=y%findPower(10, n/2);

    long long ac, bd, z;

    ac = multiplyKaratsuba(a,c,n/2);
    bd = multiplyKaratsuba(b,d,n/2);
    z = multiplyKaratsuba(a+b,c+d,n/2);

    return ac*findPower(10,n) + (z-ac-bd)*findPower(10,n/2) + bd;
}


int main(){

    cout << multiplyKaratsuba(785241,695824,6) << endl;

    return 0;
}