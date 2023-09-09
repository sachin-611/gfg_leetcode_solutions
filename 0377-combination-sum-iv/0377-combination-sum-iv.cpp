class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&a,int tar,int i){
        if(tar==0){
            return 1;
        }
        if(i==a.size()){
            return 0;
        }
        
        int &cnt=dp[i][tar];
        if(cnt!=-1)
            return cnt;
        cnt=0;
        if(tar>=a[i]){
            cnt+=solve(a,tar-a[i],0);
        }
        cnt+=solve(a,tar,i+1);
        return cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dp.resize(nums.size(),vector<int>(target+1,-1));
        return solve(nums,target,0);
    }
};