#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.front() > target || nums.back() < target)
            return -1;

        const int* begin = &nums.front();
        const int* end = &nums.back();
        const int* cur = begin + (end - begin + 1)/2;

        while (begin != end) {
            if(*cur < target)
                begin = cur+1;
            else if (*cur == target)
                return cur - &nums.front();
            else
                end = cur-1;
            cur = begin + (end - begin + 1)/2;
            cout << cur - &nums.front() << endl;
        }
        if (*cur != target)
            return -1;
        return cur - &nums.front();
    }
};

int main()
{
    vector<int> arr = {0,1,3};
    int target = 2;
    Solution sol = Solution();
    int res = sol.search(arr, target);
    cout << res << endl;
}