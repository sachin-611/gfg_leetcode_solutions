class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        queue<vector<int>>q;
        int n=graph.size();
        vector<int>vis(n);
        q.push({0});
        while(q.empty()==false){
            auto temp=q.front();
            q.pop();
            int node=temp.back();
            if(node==n-1){
                res.push_back(temp);
                continue;
            }
            for(int child:graph[node]){
                if(vis[child]==0){
                    temp.push_back(child);
                    q.push(temp);
                    temp.pop_back();
                }
            }
        }
        return res;
    }
};