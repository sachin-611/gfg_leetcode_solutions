class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0;
        int i=0,n=nums.size();
        while(i<n){
            if(nums[i]!=0){
                i++;
                continue;
            }
            int cnt=0;
            while(i<n and nums[i]==0){
                i++;
                cnt++;
            }
            res=res+((cnt)*(long long)(cnt+1))/2;
        }
        return res;
    }
};