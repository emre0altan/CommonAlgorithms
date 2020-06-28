#include <iostream>

using namespace std;

/**
 *Finds power of a number by divide and conquer
 *
 *@param x base 
 *@param y power
 *@return power of x by y or -1 if y<0
 */
int findPower(int x, int y){
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

int main(){

    cout << findPower(-2, 5) << endl;

    return 0;
}