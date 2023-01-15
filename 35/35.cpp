#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int* begin = &nums.front();
        const int* end = &nums.back();
        const int* cur = begin + (end - begin)/2;

        cout << cur - &nums.front() << " " << begin - &nums.front() << " " << end - &nums.front() << endl;
        while (begin < end) {
            if(*cur < target)
                begin = cur+1;
            else if (*cur == target)
                return cur - &nums.front();
            else
                end = cur-1;
            cur = begin + (end - begin)/2;
            cout << cur - &nums.front() << " " << begin - &nums.front() << " " << end - &nums.front() << endl;
        }

        if (*cur >= target)
            return cur - &nums.front();
        else
            return cur - &nums.front() + 1;
    }
};

int main()
{
    // vector<int> arr = {0,1,2,3,4,6};
    // int target = 5; // 5

    // vector<int> arr = {1};
    // int target = 2; // 1

    // vector<int> arr = {1};
    // int target = 0; // 0

    // vector<int> arr = {1,3};
    // int target = 4; // 2

    // vector<int> arr = {2,3,4,5,6};
    // int target = 1; // 0

    vector<int> arr = {2,3,4,5,6};
    int target = 7;

    Solution sol = Solution();
    int res = sol.searchInsert(arr, target);
    cout << res << endl;
}