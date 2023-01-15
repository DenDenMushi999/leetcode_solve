#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>::const_iterator left = nums.begin();
        vector<int>::const_reverse_iterator right = nums.rbegin();

        vector<int> ans(n);
        for( vector<int>::iterator it=nums.begin(); it<nums.end(); ++it){
            *it = *it * (*it);
        }

        vector<int>::reverse_iterator out_iter = ans.rbegin();
        while(out_iter < ans.rend()){
            *out_iter++ = *left>*right ? *left++ : *right++;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {-4,-1,0,3,4,5,6,7,8,9,10};
    // vector<int> nums = {3};
    // vector<int> nums = {-3};
    // vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {-5,-3,-2,-1};
    // vector<int> nums = {-2,-1,3};
    // vector<int> nums = {-4,-3,-2,3,3};
    // vector<int> nums = {2,2};
    // vector<int> nums = {-23,-23,-21,-19,-17,-16,-15,-14,-14,-9,-6,-6,-6,-4,-3,-3,-3,1,4,11,15,16,20,21,22};
    // vector<int> nums = {-23,-23,-21,-19,-17,-16,-15,-14,-14,-9,-7,-7,-7,-6,-5,-4,-3,1,4,11,15,16,20,21,22};
    // vector<int> nums = {-4,-1,-1,-1,-1,0,3,4,5,6,7,8,9,10};
    // vector<int> nums = {-4,-1,-1,0,0,0,0,0,0,0,0,3,4,5,6,7,8,9,10};
    vector<int> nums = {-50,-49,-48,-48,-47,-46,-46,-43,-40,-39,-37,-28,-27,-25,-18,-17,-13,
                           -12,-11,-11,-10,-9,-7,-6,-6,-3,-3,1,1,3,8,11,11,15,16,18,28,28,30,
                           30,33,34,38,39,42,43,47,47,50,50};


    for (auto iter:nums)
        cout << iter << " " ;
    cout << endl;

    Solution sol;
    vector<int> squares = sol.sortedSquares(nums);
    for (auto iter:squares)
        cout << iter << " " ;
    cout << endl;
}