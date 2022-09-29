class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int,vector<int>>m;
        for(int i:arr)
            m[abs(i-x)].push_back(i);
        vector<int>ans;
        for(auto i:m)
        {
            for(auto j:i.second)
            {
                if(k==ans.size())
                {   
                    sort(ans.begin(),ans.end());
                    return ans;
                }
                ans.push_back(j);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};