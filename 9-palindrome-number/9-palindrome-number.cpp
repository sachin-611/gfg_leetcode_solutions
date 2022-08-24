class Solution {
public:
    bool isPalindrome(long long x) {
        if(x<0)
            return false;
        long long temp=x;
        long long news=0;
        while(temp)
        {
            news*=10;
            news+=temp%10;
            temp/=10;
        }
        return x==news;
    }
};