class Solution {
public:
    vector<bool>vis;
    vector<int>dp;
    int rob(vector<int>& nums,int i=0) {
        if(i==0)
            vis.resize(nums.size(),0),dp.resize(nums.size(),-1);
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int p1=rob(nums,i+1);
        if(i==0 or (i>0 and vis[i-1]==0))
            p1=max(p1,rob(nums,i+2)+nums[i]);
        return dp[i]=p1;
    }
};