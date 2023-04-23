class Solution {
public:
     int dp[100004];
    int mod=1000000007;
    int numberOfArrays(string &s, int &k,int i=0) {
        if(i==0){
            memset(dp,-1,sizeof(dp));
        }
        if(i==s.size())
            return 1;
        int &res=dp[i];
        if(res!=-1)
            return res;
        res=0;
        long long nums=0;
        for(int j=i;j<s.size();j++){
            nums=nums*10+(s[j]-'0');
            if(nums==0)
                return 0;
            if(nums>k)
                break;
            res=(res+numberOfArrays(s,k,j+1))%mod;
        }
        return res%=mod;
    }
};