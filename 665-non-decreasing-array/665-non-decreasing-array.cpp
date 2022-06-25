class Solution {
public:
    bool ok(vector<int>&nums,int pos,int used,int n)
    {
        if(used)
        {
            bool res=0;
            for(int i=1;i<n;i++)
            {
                if(nums[i]<nums[i-1])
                    return 0;
            }
            return 1;
        }
        if(pos==n)
            return 1;
        if(nums[pos]>=nums[pos-1])
            return ok(nums,pos+1,used,n);
        else
        {
            int val=nums[pos];
            nums[pos]=nums[pos-1];
            int pos1=ok(nums,pos+1,1,n);
            nums[pos]=val;
            val=nums[pos-1];
            nums[pos-1]=nums[pos];
            int pos2=ok(nums,pos+1,1,n);
            nums[pos-1]=val;
            if(pos+1<n)
                val=nums[pos+1];
            nums[pos]=val;
            int pos3=ok(nums,pos+1,1,n);
            return pos1||pos2||pos3;
        }
    }
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        return ok(nums,1,0,n);
    }
};