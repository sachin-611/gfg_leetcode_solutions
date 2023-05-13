class Solution {
public:
    long long dp[100005];
    long long res(int i,vector<vector<int>>&q,int n){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        long long p1=res(i+1,q,n);
        long long p2=res(i+q[i][1]+1,q,n)+q[i][0];
        return dp[i]=max(p1,p2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return res(0,questions,questions.size());
    }
};