class Solution {
public:
    bool isPerfectSquare(int num) {
        int v=sqrt(num);
        return v*v==num;
    }
};