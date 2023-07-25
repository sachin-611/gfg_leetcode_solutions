class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1,r=arr.size()-2;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid]<arr[mid+1]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }
};