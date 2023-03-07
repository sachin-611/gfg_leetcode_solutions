class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end()),right=1e8;
        int ans=-1;
        while(left<=right){
            int mid=(right-left)/2+left;
            int dat=0;
            int j=0;
            while(j<weights.size()){
                dat++;
                int temp=0;
                while(j<weights.size() and temp+weights[j]<=mid){
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