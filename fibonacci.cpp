#include <iostream>

using namespace std;

/**
 *Finds fibonacci number by divide and conquer 
 * 
 *@param x index of fibonacci number 
 *@return fibonacci number at x
 */

int findFibonacci(int x){
    if(x == 0)
        return 0;
    else if(x == 1)
        return 1;
    else if(x > 1){
        return findFibonacci(x-1)+findFibonacci(x-2);
    }else{
        return -1;
    }
}

int main(){

    cout << findFibonacci(8) << endl;

    return 0;
}