// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1)
            return 1;

        int begin = 1;
        int end = n;
        int cur;

        while (end >= begin) {
            cur = (end - begin - 1)/2;
            if(isBadVersion(cur))
                end = cur;
            else
                begin = cur+1;
            cur = begin + (end - begin - 1)/2;
            cout << cur << endl;
        }
        return cur;
    }
};