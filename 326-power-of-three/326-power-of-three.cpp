class Solution {
public:
    bool isPowerOfThree(int n) {
        long long i=1;
        while(i<n)
        {
            i*=3;
        }
        return i==n;
    }
};