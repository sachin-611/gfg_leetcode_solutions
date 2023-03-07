class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=-1,n=weights.size(),left=0, right=0;
        for(auto i:weights){
            left=max(left,i);
            right+=i;
        }
        while(left<=right){
            int mid=(right-left)/2+left;
            int dat=0;
            int j=0;
            while(j<n){
                dat++;
                int temp=0;
                while(j<n and temp+weights[j]<=mid){
                    temp+=weights[j];
                    j++;
                }
            }
            if(dat<=days){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};