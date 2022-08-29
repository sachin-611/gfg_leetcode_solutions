class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1,n=nums.size();
        while(i<n)
        {
            if(nums[i]==nums[i-1])
                i++;
            else
            {
                nums[j]=nums[i];
                j++;
                i++;
            }
        }
        // while((int)nums.size()!=j)
        //     nums.pop_back();
        // cout<<nums.size();
        return j;
    }
};