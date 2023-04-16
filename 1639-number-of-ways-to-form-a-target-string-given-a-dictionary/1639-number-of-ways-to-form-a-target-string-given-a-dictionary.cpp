class Solution {
public:
    vector<vector<int>>a,dp;
    long long mod;
    long long solve(int i,int j,string &target){
        if(i==target.size())
            return 1;
        if(j==a.size())
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long cnt=solve(i,j+1,target)%mod;
        long long cnt2=0;
        if(a[j][target[i]-'a']>0)
           cnt2=(solve(i+1,j+1,target)%mod*a[j][target[i]-'a'])%mod;
        return dp[i][j]=(cnt+cnt2)%mod;
        
    }
    long long numWays(vector<string>& words, string target) {
        a.resize(words[0].size(),vector<int>(26,0));
        dp.resize(target.size(),vector<int>(a.size(),-1));
        mod=1e9+7;
        for(int i=0;i<words[0].size();i++){
            for(string &j:words){
                a[i][j[i]-'a']++;
            }
        }
        return solve(0,0,target);
    }
};