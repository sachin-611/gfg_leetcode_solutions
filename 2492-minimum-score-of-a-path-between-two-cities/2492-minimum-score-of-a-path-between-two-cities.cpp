class Solution {
public:
    vector<int>vis;
    unordered_map<int,vector<pair<int,int>>>m;
    void dfs(int node)
    {
        vis[node]=1;
        for(auto i:m[node])
        {
            if(vis[i.first]==0)
            {
                dfs(i.first);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vis.resize(n,0);
        for(auto &i:roads)
        {
            m[i[0]-1].push_back({i[1]-1,i[2]});
            m[i[1]-1].push_back({i[0]-1,i[2]});
        }
        dfs(0);
        int res=1e9;
        for(auto &i:roads)
        {
            // cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
            if(vis[i[0]-1]==1 || vis[i[1]-1]==1)
            {
                res=min(res,i[2]);
                // cout<<i[2]<<endl;
            }
        }
        return res;
    }
};