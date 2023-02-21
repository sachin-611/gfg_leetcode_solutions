class Solution {
    int isodd(vector<int>&nums,int &ind,int prev){
        if(nums[ind]!=nums[ind-1] and nums[ind]!=nums[ind+1]){
            return 69;
        }
        if(nums[ind]==nums[ind-1] ){
            if(prev%2==0){
                return -2;
            }
            else{
                return 1;
            }
        }
        if(nums[ind]==nums[ind+1]){
            if(prev%2==0){
                return 2;
            }
            else{
                return -1;
            }
        }
        return 2;
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int val=isodd(nums,mid,mid-low);
                
            if(val==69){
                return nums[mid];
            }
            if(val<0){
                high=mid+val;
            }
            else{
                low=mid+val;
            }
        }
        return -1;
    }
};