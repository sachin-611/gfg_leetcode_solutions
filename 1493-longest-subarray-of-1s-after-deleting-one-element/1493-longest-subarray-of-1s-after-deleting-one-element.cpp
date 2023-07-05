class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            pre[i]=cnt;
            if(nums[i]!=1){
                cnt=0;
            }else{
                cnt++;
            }
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            suf[i]=cnt;
            if(nums[i]!=1){
                cnt=0;
            }else{
                cnt++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,pre[i]+suf[i]);
        }
        return ans;
    }
};