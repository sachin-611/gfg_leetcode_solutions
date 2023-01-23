class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>m;
        vector<vector<int>>a(n);
        for(auto &i:trust)
        {
            m[i[1]-1]++;
            a[i[0]-1].push_back(i[1]-1);
        }
        for(int i=0;i<n;i++)
        {
            if(m[i]==n-1 and a[i].empty())
                return i+1;
        }
        return -1;
    }
};