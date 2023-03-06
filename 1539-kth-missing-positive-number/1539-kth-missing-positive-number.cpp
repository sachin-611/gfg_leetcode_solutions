class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int ind=0,n=arr.size();
        // for(int i=1;;i++){
        //     if(ind<n and arr[ind]==i){
        //         ind++;
        //     }else{
        //         k--;
        //     }
        //     if(k==0){
        //         return i;
        //     }
        // }
        // return -1;
        int l=0,r=arr.size()-1,mid;
        int ans=r+1+k;
        while(l<=r){
            mid=(l+r)>>1;
            if(arr[mid]-mid-1>=k){
                ans=mid+k;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};