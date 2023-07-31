class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j){
        if(i==n){
            int res=0;
            for(int k=j;k<m;k++){
                res+=s2[k];
            }
            return res;
        }
        if(j==m){
            int res=0;
            for(int k=i;k<n;k++){
                res+=s1[k];
            }
            return res;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int &p1=dp[i][j];
        p1=solve(s1,s2,i+1,j)+s1[i];
        if(s1[i]==s2[j]){
            p1=min(p1, solve(s1,s2,i+1,j+1));
            return p1;
        }
        p1=min(p1,solve(s1,s2,i,j+1)+s2[j]);
        return p1;
    }
    int minimumDeleteSum(string s1, string s2) {
        n=s1.size(),m=s2.size();
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);
    }
};