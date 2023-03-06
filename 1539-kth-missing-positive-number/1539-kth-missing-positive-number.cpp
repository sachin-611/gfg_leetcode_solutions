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