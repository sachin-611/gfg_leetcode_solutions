vector<vector<int>>dp(1001,vector<int>(1001));
class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int j, int k, vector<int> &a, vector<int> &b){
//         if (j == M.size()) return 0;
//         if (dp[i][j] != INT_MIN) return dp[i][j];
//         // Left Side
//         int left = solve(i + 1, n, j + 1, nums, M) + (nums[i] * M[j]);
//         // Right Side
//         int right = solve(i, n, j + 1, nums, M) + (nums[(n - 1) - (j - i)] * M[j]);
//         return dp[i][j] = max(left, right);
        if(j==b.size())return 0;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
        int val1=solve(i+1,j+1,k,a,b)+b[j]*a[i];
        int val2=solve(i,j+1,k+1,a,b)+b[j]*a[a.size()-1-k];
        return dp[i][j]=max(val1,val2);
    }
    
//     int maximumScore(vector<int>& nums, vector<int>& M) {   
//         int n = nums.size(), m = M.size();
//         dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
//         return solve(0, n, 0, nums, M);
//     }
    int maximumScore(vector<int>& a, vector<int>& b) {
        dp.resize(b.size() + 1, vector<int>(b.size() + 1, INT_MIN));
        return solve(0,0,0,a,b);
    }
};