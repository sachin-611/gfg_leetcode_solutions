class Solution {
public:
    vector<vector<int>>gcd;
    vector<int>dp;
    int n;
    int solve(int vis,int i,vector<int>&a){
        if(i==0)
            return 0;
        int &score=dp[vis];
        if(score!=-1)
            return score;
        score=0;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((vis&(1<<j)) and (vis&(1<<k))){
                    (vis^=(1<<j));
                    (vis^=(1<<k));
                    // vis[k]=0;
                    score=max(score,solve(vis,i+1,a)+i*(gcd[j][k]));
                    (vis^=(1<<j));
                    (vis^=(1<<k));
                }
            }
        }
        return score;
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        gcd.resize(n,vector<int>(n));
        dp.resize((1<<15),-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                gcd[i][j]=__gcd(nums[i],nums[j]);
            }
        }
        int vis=(1<<15)-1;
        return solve(vis,1,nums);
    }
};