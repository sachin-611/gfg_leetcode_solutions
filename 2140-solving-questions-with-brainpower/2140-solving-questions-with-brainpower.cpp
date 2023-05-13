class Solution {
public:
    long long dp[100005];
        int n;
    long long mostPoints(vector<vector<int>>& q,int i=0) {
        if(i==0){
            n=q.size();
            memset(dp,-1,sizeof(long long)*n);
        }
        if(i>=n){
            return 0;
        }
        long long &res=dp[i];
        if(res!=-1){
            return res;
        }
        res=mostPoints(q,i+1);
        res=max(res,mostPoints(q,i+q[i][1]+1)+q[i][0]);
        return res;
    }
};