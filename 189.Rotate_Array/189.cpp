#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k = k % n;
        nums.resize(nums.size()+k);

        vector<int>::iterator it1 = nums.end()-k-1;
        vector<int>::iterator it2 = nums.end()-1;

        while (it1>=nums.begin())
            *it2-- = *it1--;

        it1 = nums.begin();
        it2 = nums.end()-k;
        while (it1 < nums.begin()+k){
            *(it1++) = *(it2++);
        }
        nums.resize(n);
    }
};

int main(){
    // vector<int> vec = {1,2,3,4,5};
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12};
    for (auto it:vec)
        cout << it << " ";
    cout << endl;

    Solution sol;
    sol.rotate(vec, 5);
    for (auto it:vec)
        cout << it << " ";
    cout << endl;

}
