class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,int n,vector<vector<int>>&a){
        if(i==n-1)
            return dp[i][j]=a[i][j];
        if(dp[i][j]!=1e9)
            return dp[i][j];
        int &p1=dp[i][j];
        p1=solve(i+1,j,n,a)+a[i][j];
        if(j-1>=0)
            p1=min(p1,solve(i+1,j-1,n,a)+a[i][j]);
        if(j+1<n)
            p1=min(p1,solve(i+1,j+1,n,a)+a[i][j]);
        return p1;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e9;
        int n=matrix.size();
        dp.resize(n+1,vector<int>(n+1,1e9));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(0,i,n,matrix));
        }
        return ans;
    }
};