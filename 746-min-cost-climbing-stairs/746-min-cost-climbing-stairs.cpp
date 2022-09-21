class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&cost,int i)
    {
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int p1=0;
        if(i+1<cost.size())
            p1=solve(cost,i+1)+cost[i+1];
        if(i+2<cost.size())
        p1=min(p1,solve(cost,i+2)+cost[i+2]);
        else
            p1=min(p1,0);
        return dp[i]=p1;
    }
    int minCostClimbingStairs(vector<int>& cost, int i=-1) {
        dp.resize(cost.size(),-1);
        int ans=solve(cost,0)+cost[0];
            dp.resize(cost.size(),-1);
        ans=min(ans,solve(cost,1)+cost[1]);
        return ans;
    }
};