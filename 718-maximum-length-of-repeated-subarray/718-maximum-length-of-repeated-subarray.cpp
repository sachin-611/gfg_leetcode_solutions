        vector<vector<int>>dp(1001,vector<int>(1001));
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int res=0;
        for(int i=0;i<n;i++)
            dp[i][0]=0;
        for(int j=0;j<m;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=(nums1[i-1]==nums2[j-1]?(dp[i-1][j-1])+1:0);
                if(dp[i][j]>res)
                    res=dp[i][j];
            }
        }
        return res;
    }
};