class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int n=nums.size();
        deque<pair<int,int>>q;
        for(int i=0;i<n;i++){
            while(q.empty()==false and q.front().second<=i-k){
                q.pop_front();
            }
            while(q.empty()==false and q.back().first<nums[i]){
                q.pop_back();
            }
            q.push_back({nums[i],i});
            if(i>=k-1){
                res.push_back(q.front().first);
            }
        }
        return res;
    }
};