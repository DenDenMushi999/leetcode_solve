#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int>::iterator searchClosesToNumberFirst(vector<int>& nums, int target) {
    // output iterator index is >= 0 and <= nums.size()
        if (nums.size() == 1 || nums.front() > target)
            return nums.begin();

        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end() - 1;
        vector<int>::iterator cur = begin + (end - begin)/2;

        while (begin < end ) {
            if(*cur < target)
                begin = cur+1;
            else
                end = cur;
            cur = begin + (end - begin)/2;
        }

        if (cur == nums.end())
            return cur - 1;
        if (cur != nums.begin())
            return abs(*cur) < abs(*(cur-1)) ? cur : cur-1;

        return cur;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> out(nums.size());
        vector<int>::const_iterator nums_end = nums.end();
        vector<int>::const_reverse_iterator nums_rend = nums.rend();
        vector<int>::const_iterator begin = searchClosesToNumberFirst(nums, 0);
        vector<int>::const_iterator pos_iter = begin + 1;
        vector<int>::const_reverse_iterator neg_iter = make_reverse_iterator(begin)-1;

        vector<int>::iterator out_iter = out.begin();
        while (neg_iter < nums_rend && pos_iter < nums_end) {
             if (abs(*neg_iter) < abs(*pos_iter)) {
                *out_iter = *neg_iter* (*neg_iter);
                ++neg_iter;
            }
            else{
                *out_iter = *pos_iter* (*pos_iter);
                ++pos_iter;
            }
            ++out_iter;
        }

        if (neg_iter == nums_rend){
            for (;pos_iter != nums_end; ++pos_iter, ++out_iter)
                *out_iter = *pos_iter* (*pos_iter);
        }
        else
            for (;neg_iter != nums_rend; ++neg_iter, ++out_iter)
                *out_iter = *neg_iter* (*neg_iter);

        return out;
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