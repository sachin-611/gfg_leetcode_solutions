class Solution {
    int dp[202][202];
public:
    int minPathSum(vector<vector<int>>& a) {
        memset(dp,-1,sizeof(dp));
        int m=a.size();
        int n=a[0].size();
        return solve(0,0,m,n,a);
    }
    int solve(int i,int j,int n,int m,vector<vector<int>>&a)
    {
        if(i==n-1 && j==m-1)
            return a[i][j];
        if(i==n || j==m)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int pos=min(solve(i,j+1,n,m,a),solve(i+1,j,n,m,a));
        if(pos==INT_MAX)
            return dp[i][j]=pos;
        return dp[i][j]=pos+a[i][j];
    }
};