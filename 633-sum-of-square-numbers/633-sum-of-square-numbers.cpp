#define ll long long
class Solution {
public:
    bool judgeSquareSum(ll c) {
        ll i=0,j=0;
        while(j*j<c)
            j++;
        while(i<j and i*i+j*j!=c)
        {
            if(i*i+j*j>c)
                j--;
            else
                i++;
        }
        return i*i+j*j==c;
    }
};