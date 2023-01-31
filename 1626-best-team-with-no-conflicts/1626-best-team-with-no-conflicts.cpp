class Solution {
    vector<pair<int,int>>a;
    vector<vector<int>>dp;
    int cal(int i,int total,int last){
        if(i>=a.size())
            return 0;
        int &ans=dp[i][last+1];
        if(ans!=-1)
            return ans;
        if(last==-1 || a[last].second<=a[i].second){
            ans=cal(i+1,total+a[i].second,i)+a[i].second;
        }
        ans=max(ans,cal(i+1,total,last));
        return ans;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        a.resize(n);
        dp.resize(n+2,vector<int>(n+2,-1));
        for(int i=0;i<n;i++){
            a[i].first=ages[i];
            a[i].second=scores[i];
        }
        sort(a.begin(),a.end());
        return cal(0,0,-1);
    }
};