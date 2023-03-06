class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
        }   
        res.push_back(m.rbegin()->first);
        for(int i=k;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i-k]]==1){
                m.erase(nums[i-k]);
            }else{
                m[nums[i-k]]--;
            }
            res.push_back(m.rbegin()->first);
        }
        return res;
    }
};