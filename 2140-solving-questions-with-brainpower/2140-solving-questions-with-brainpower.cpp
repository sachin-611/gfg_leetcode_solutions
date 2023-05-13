class Solution {
public:
    vector<long long>dp;
        int n;
    long long mostPoints(vector<vector<int>>& q,int i=0) {
        if(i==0){
            n=q.size();
            dp.resize(n,-1);
        }
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=max(mostPoints(q,i+1),mostPoints(q,i+q[i][1]+1)+q[i][0]);
    }
};