class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int n=nums.size();
        for(int i=0;i<n;)
        {
            string temp=to_string(nums[i]);
            int cnt=0;
            while(i+1<n and nums[i+1]==nums[i]+1)
            {
                i++;
                cnt++;
            }
            if(cnt)
            {
                temp=temp+"->"+to_string(nums[i]);
            }
            res.push_back(temp);
            i++;
        }
        return res;
    }
};