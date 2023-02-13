class Solution {
    unordered_map<int,vector<int>>m;
    long long ans;
    int seat;
    vector<int>vis;
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_set<int>cnt;
        for( auto &i:roads){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        ans=0;
        seat=seats;
        vis.resize(roads.size()+1);
        dfs(0);
        return ans;
    }
    int dfs(int node){
        vis[node]=1;
        int res=1;
        for(auto &child:m[node]){
            if(vis[child]==0){
                int temp=dfs(child);
                ans+=(temp+seat-1)/seat;  
                res+=temp;
            }
        }
        return res;
    }
};