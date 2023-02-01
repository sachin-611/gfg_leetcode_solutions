class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n*2)/__gcd(2,n);
    }
};