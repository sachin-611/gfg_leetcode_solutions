class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>a;
        map<int,vector<int>>b;
        for(int i:nums)
            a[i]++;
        for(auto i:a)
            b[i.second].push_back(i.first);
        vector<int>res;
        for(auto it=b.rbegin();it!=b.rend() and k;it++){
            for(int j:it->second){
                if(k){
                    res.push_back(j);
                    k--;
                }
            }
        }
        return res;
    }
};