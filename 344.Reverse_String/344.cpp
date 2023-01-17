#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 1)
            return;
        vector<char>::iterator it = s.begin();
        vector<char>::reverse_iterator it_r = s.rbegin();
        vector<char>::iterator end = s.begin()+ s.size()/2;
        while (it < end){
            iter_swap(it++, it_r++);
        }
    }
};

int main(){
    // vector<char> vec = {'h','e','l','l','o'};
    // vector<char> vec = {'H','a','n','n','a','h'};
    vector<char> vec = {'H','a','N','n','N','n','a','h'};
    for (auto it:vec)
        cout << it << " ";
    cout << endl;

    Solution sol;
    sol.reverseString(vec);
    for (auto it:vec)
        cout << it << " ";
    cout << endl;

}