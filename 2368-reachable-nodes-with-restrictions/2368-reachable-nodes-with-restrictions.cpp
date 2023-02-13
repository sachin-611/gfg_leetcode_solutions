class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int cnt=0;
        vector<vector<int>>m(n);
        vector<int>ok(n);
        for(auto &i:restricted){
            ok[i]=1;
        }
        vector<int>vis(n);
        for(auto &i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            cnt++;
            int node=q.front();
            q.pop();
            for(auto &child:m[node]){
                if(vis[child]==0 and ok[child]==0){
                    vis[child]=1;
                    q.push(child);
                }
            }
        }
        return cnt;
    }
};