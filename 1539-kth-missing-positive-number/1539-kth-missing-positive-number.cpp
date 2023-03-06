class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        int ans=r+1+k;
        while(l<=r){
            if(arr[((l+r)/2)]-((l+r)/2)-1>=k){
                ans=((l+r)/2)+k;
                r=((l+r)/2)-1;
            }else{
                l=((l+r)/2)+1;
            }
        }
        return ans;
    }
};