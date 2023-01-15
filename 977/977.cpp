#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int>::iterator searchInsertIter(vector<int>& nums, int target) {
        vector<int>::iterator begin = nums.begin();
        vector<int>::iterator end = nums.end();
        vector<int>::iterator cur = begin + (end - begin - 1)/2;

        cout << cur - nums.begin() << " " << begin - nums.begin() << " " << end - nums.begin() << endl;
        while (begin < end) {
            if(*cur < target)
                begin = cur+1;
            else if (*cur == target)
                return cur;
            else
                end = cur-1;
            cur = begin + (end - begin)/2;
            cout << cur - nums.begin() << " " << begin - nums.begin() << " " << end - nums.begin() << endl;
        }

        if (*cur >= target)
            return cur;
        else
            return cur + 1;
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
        vector<int>::const_iterator begin = searchInsertIter( nums, 0);
        vector<int>::const_iterator pos_iter = begin + 1;
        vector<int>::const_reverse_iterator neg_iter = make_reverse_iterator(begin) - 1;

        vector<int>::iterator out_iter = out.begin();
        while (neg_iter < nums.rend() && pos_iter < nums.end()) {
            cout << "neg: " << *neg_iter << ", pos: " << *pos_iter << endl;
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
    // vector<int> nums = {1};
    vector<int> nums = {-1};
    for (auto iter:nums)
        cout << iter << " " ;
    cout << endl;

    Solution sol;
    vector<int> squares = sol.sortedSquares(nums);
    for (auto iter:squares)
        cout << iter << " " ;
    cout << endl;
}