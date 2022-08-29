class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0, i=0;
        while(i<nums.size())
        {
            nums[j]=nums[i];
            if(nums[i]!=val)
                j++;
            i++;
        }
        return j;
    }
};