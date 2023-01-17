#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k = k % n;

        int buf;
        int incr;
        vector<int>::iterator begin;
        vector<int>::iterator end;
        if (k<n/2){
            incr=-1;
            begin = nums.end()-1;
            end = nums.begin();
        }
        else{
            k = n-k;
            incr=1;
            begin = nums.begin();
            end = nums.end()-1;
        }
        for (int i=0; i<k; ++i){
            for (vector<int>::iterator it = begin; it!=end; it+=incr){
                buf = *(it+incr);
                *(it+incr) = *it;
                *it = buf;
            }
        }
    }
};

int main(){
    // vector<int> vec = {1,2,3,4,5};
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12};
    cout << vec.size() << endl;

    const int k = 54944;
    Solution sol;
    sol.rotate(vec, k);
}
