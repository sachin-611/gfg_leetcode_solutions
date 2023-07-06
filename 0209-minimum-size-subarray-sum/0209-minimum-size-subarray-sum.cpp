class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,h=0,sum=0,n=nums.size();
        int ans=n+1;
        while(l<n and h<n){
            while(h<n and sum<target){
                sum+=nums[h];
                h++;
            }
            while(l<n and sum>=target){
                sum-=nums[l];
                ans=min(ans,h-l);
                l++;
            }
        }
        if(ans==n+1){
            ans=0;
        }
        return ans;
    }
};