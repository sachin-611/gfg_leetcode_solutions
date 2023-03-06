class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int n=nums.size();
        multiset<int>m;
        for(int i=0;i<k;i++){
            m.insert(nums[i]);
        }   
        res.push_back(*m.rbegin());
        for(int i=k;i<n;i++){
            m.insert(nums[i]);
            m.erase(m.lower_bound(nums[i-k]));
            res.push_back(*m.rbegin());
        }
        return res;
    }
};