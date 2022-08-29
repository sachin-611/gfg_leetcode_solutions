class Solution {
public:
    double myPow(double x, long n) {
        bool neg=n<0;
        if(neg)
            n=-1*n;
        double res=1;
        while(n)
        {
            if(n&1)
            {
                res*=x;
            }
            x=x*x;
            n=n/2;
        }
        if(neg)
            return 1/res;
        return res;
    }
};