class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=0;
        for(auto i:nums)
        {
            if(i>=target)
                break;
            ans++;
        }
        return ans;
    }
};