#include <iostream>
#include <vector>

using namespace std;

/**
 *Finds an element in a sorted vector by divide and conquer
 *
 *@param arr sorted vector
 *@param val value that we are looking for
 *@param begin start position for searching in vector
 *@param end end position for searchin in vector
 *@return index of element or -1 if element does not exist in vector
 */
int findElementSorted(vector<int> arr, int val, int begin, int end){
    int ind;
    if(arr[(end-begin)/2+begin] < val && end > begin){
        ind = findElementSorted(arr, val, (end-begin)/2+1+begin,end);
    }else if(arr[(end-begin)/2+begin] > val && end > begin){
        ind = findElementSorted(arr, val, begin, (end-begin)/2-1+begin);
    }else if(arr[(end-begin)/2+begin] == val){
        return (end-begin)/2+begin;
    }else if(end == begin){
        return -1;
    }
    return ind;
}


int main(){

    vector<int> a = {3, 5, 7, 8, 9, 12, 15};

    cout << findElementSorted(a, 15, 0, a.size()-1) << endl;

    return 0;
}