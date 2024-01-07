class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<long long, long long>> dp(n);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long diff = (long long)nums[i] - (long long) nums[j];
                dp[i][diff] += dp[j][diff]+1;
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};