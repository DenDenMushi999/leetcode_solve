#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int>::iterator searchClosesToZero(vector<int>& nums) {
        if (nums.size() == 1)
            return nums.begin();
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();
        vector<int>::iterator cur = begin + (end - begin - 1)/2;

        while (begin < end) {
            if(*cur < 0)
                begin = cur+1;
            else if (*cur == 0)
                return cur;
            else
                end = cur-1;
            cur = begin + (end - begin)/2;
        }

        if (cur == nums.end())
            return cur - 1;
        if (cur != nums.begin())
            return abs(*cur) < abs(*(cur-1)) ? cur : cur-1;

        return cur;

        // if (*cur >= 0)
        //     return cur;
        // else
        //     return cur + 1;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        // create new vector
        // use const input iterator for input
        // and use output iteratir for output vector

        // Alg:
        // - find the closest to zero element, and start with it
        // - then go to negatvie or positive number depending on what is less in module
        // - create 2 iterators (maybe forward) for input, and move them by iterations

        vector<int> out(nums.size());
        vector<int>::const_iterator begin = searchClosesToZero(nums);
        vector<int>::const_iterator pos_iter = begin + 1;
        vector<int>::const_reverse_iterator neg_iter = make_reverse_iterator(begin)-1;

        cout << "begin: " << begin - nums.begin() << endl;
        cout << "neg_iter: " << nums.rend() - neg_iter << ", neg = " << *neg_iter <<endl;

        vector<int>::iterator out_iter = out.begin();
        while (neg_iter < nums.rend() && pos_iter < nums.end()) {
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

        if (neg_iter == nums.rend()){
            for (;pos_iter != nums.end(); ++pos_iter, ++out_iter)
                *out_iter = *pos_iter* (*pos_iter);
        }
        else
            for (;neg_iter != nums.rend(); ++neg_iter, ++out_iter)
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
    vector<int> nums = {-23,-23,-21,-19,-17,-16,-15,-14,-14,-9,-7,-7,-7,-6,-5,-4,-3,1,4,11,15,16,20,21,22};

    for (auto iter:nums)
        cout << iter << " " ;
    cout << endl;

    Solution sol;
    vector<int> squares = sol.sortedSquares(nums);
    for (auto iter:squares)
        cout << iter << " " ;
    cout << endl;
}