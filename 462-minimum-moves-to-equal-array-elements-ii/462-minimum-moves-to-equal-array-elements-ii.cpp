class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans=0,sum=0;
        sort(nums.begin(),nums.end());
        sum=((nums.size()&1)?nums[nums.size()/2]:(nums[nums.size()/2]+nums[(nums.size()-1)/2])/2);
        for(int i:nums)
            ans+=abs(i-sum);
        return ans;
    }
};