class Solution {
public:
    vector<long long>dp;
        int n;
    long long res(int i,vector<vector<int>>&q){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=max(res(i+1,q),res(i+q[i][1]+1,q)+q[i][0]);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        dp.resize(n,-1);
        return res(0,questions);
    }
};