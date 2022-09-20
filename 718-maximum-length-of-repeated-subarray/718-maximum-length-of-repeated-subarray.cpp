class Solution {
public:
        vector<vector<int>>dp;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        dp.resize(n+1,vector<int>(m+1));
        int res=0;
        for(int i=1;i<=n;i++)
        {
            // dp[i-1][0]=0;
            for(int j=1;j<=m;j++)
            {
                // dp[0][j-1]=0;
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                if(dp[i][j]>res)
                    res=dp[i][j];
            }
        }
        return res;
    }
};