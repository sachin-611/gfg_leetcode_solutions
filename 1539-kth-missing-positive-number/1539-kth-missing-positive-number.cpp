class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ind=0,n=arr.size();
        for(int i=1;;i++){
            if(ind<n and arr[ind]==i){
                ind++;
            }else{
                k--;
            }
            if(k==0){
                return i;
            }
        }
        return -1;
    }
};