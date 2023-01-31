class Solution {
    vector<pair<int,int>>a;
    int cal(int i,int total,int last){
        int n=a.size();
        vector<int>dp(n);
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i]=a[i].second;
            for(int j=i-1;j>=0;j--){
                if(a[i].second>=a[j].second)
                    dp[i]=max(dp[i],dp[j]+a[i].second);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        a.resize(n);
        for(int i=0;i<n;i++){
            a[i].first=ages[i];
            a[i].second=scores[i];
        }
        sort(a.begin(),a.end());
        return cal(0,0,-1);
    }
};