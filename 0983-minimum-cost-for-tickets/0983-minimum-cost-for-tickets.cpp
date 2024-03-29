class Solution {
public:
    vector<int>dp;
    int res(int i,int n,int next,vector<int>&days,vector<int>&costs){
        if(i==n){
            return 0;
        }
        if(dp[next]!=-1){
            return dp[next];
        }
        int cost=1e9;
        if(days[i]>=next){
            cost=res(i+1,n,days[i]+1,days,costs)+costs[0];
            cost=min(cost,res(i+1,n,days[i]+7,days,costs)+costs[1]);
            cost=min(cost,res(i+1,n,days[i]+30,days,costs)+costs[2]);
        }else{
            cost=res(i+1,n,next,days,costs);
        }
        return dp[next]=cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(500,-1);
        return res(0,days.size(),0,days,costs);
    }
};