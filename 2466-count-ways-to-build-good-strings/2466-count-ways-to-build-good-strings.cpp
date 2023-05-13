class Solution {
public:
    int mod=1e9+7;
    int dp[100005];
    int res;
    int count(int len,int one,int zero,int low,int high){
        if(len>high){
            return 0;
        }
        if(dp[len]!=-1)
            return dp[len];
        int p1=(count(len+one,one,zero,low,high)+(len+one>=low and len+one<=high))%mod;
        int p2=(count(len+zero,one,zero,low,high)+(len+zero>=low and len+zero<=high))%mod;
        return dp[len]=(p1+p2)%mod;
        
        
    }
    int countGoodStrings(int low, int high, int zero, int one,int len=0) {
        memset(dp,-1,sizeof(dp));
        res=0;
        return count(0,one,zero,low,high);
    }
};