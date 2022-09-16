class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& a, vector<int>& b,int i=0,int j=0,int k=0) {
        if(j==0)
            dp.resize(b.size() + 1, vector<int>(b.size() + 1, INT_MIN));
        if(j==b.size())return 0;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int val1=maximumScore(a,b,i+1,j+1,k)+b[j]*a[i];
        int val2=maximumScore(a,b,i,j+1,k+1)+b[j]*a[a.size()-1-k];
        return dp[i][j]=max(val1,val2);
    }
};