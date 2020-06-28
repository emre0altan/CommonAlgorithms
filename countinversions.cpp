#include <iostream>
#include <vector>

using namespace std;

/**
 *Merges and gives inversions by comparing two vector 
 * 
 *@param a first vector
 *@param b second vector
 *@param count parameter for inversion count
 *@return a vector merged by a and b
 */
vector<int> mergeAndCount(vector<int> a, vector<int> b, int &count){
    int ai = 0, bj =0;
    vector<int> res;
    while(ai != a.size() && bj != b.size()){
        if(a[ai] < b[bj]){
            res.push_back(a[ai]);
            ai++;
        }else{
            res.push_back(b[bj]);
            count += a.size()-ai;
            bj++;
        }
    }
    
    if(ai != a.size()){
        for(int i =ai;i<a.size();i++){
            res.push_back(a[i]);
        }
    }else if(bj != b.size()){
        for(int i =bj;i<b.size();i++){
            res.push_back(b[i]);
        }
    }
    return res;
}

/**
 *Sorts and gives inversions count in a vector 
 * 
 *@param vec vector to be sorted
 *@param inversions count of the inversions in vector
 *@return sorted vector
 */
vector<int> sortAndCount(vector<int> vec, int &inversions){
    if(vec.size() == 1){
        inversions = 0;
        return vec;
    }
    vector<int> half1,half2;
    int ra, rb, r;
    for(int i=0;i<vec.size();i++){
        if(i<vec.size()/2)
            half1.push_back(vec[i]);
        else
            half2.push_back(vec[i]);
    }
    half1 = sortAndCount(half1, ra);
    half2 = sortAndCount(half2, rb);    
    vec = mergeAndCount(half1, half2, inversions);

    return vec;
}

int main(){

    vector<int> q = {5, 1, 4, 2};
    
    int count = 0;
    q = sortAndCount(q,count);
    cout << count << endl;

    return 0;
}