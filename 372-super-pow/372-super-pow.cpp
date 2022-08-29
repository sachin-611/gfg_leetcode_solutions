class Solution {
public:
    int superPow(long long a, vector<int>& b) {
        int res=1;
        int sz=b.size();
        b.push_back(0);
        // a=a%1337;
        reverse(b.begin(),b.end());
        while(sz>0)
        {
            if(b[1]&1)
            {
                res=(res*a)%1337;
            }
            a=(a*a)%1337;
            //half
            
            for(int i=sz;i>=1;i--)
            {
                if(b[i]%2==0)
                {
                    b[i]/=2;
                }
                else
                {
                    b[i]/=2;
                    b[i-1]+=10;
                }
            }
            while(sz>0 and b[sz]==0)
                sz--;
        }
        return res;
    }
};