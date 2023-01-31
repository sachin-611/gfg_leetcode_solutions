class Solution {
    vector<pair<int,int>>a;
    map<pair<int,int>,int>dp;
    int cal(int n,int total,int last){
        vector<int>dp(n+2);
        for(int i=0;i<n;i++){
            dp[i]=a[i].second;
            for(int j=i-1;j>=0;j--){
                if(a[i].second>=a[j].second){
                    dp[i]=max(dp[i],dp[j]+a[i].second);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
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
        return cal(n,0,0);
    }
};