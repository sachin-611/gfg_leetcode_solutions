class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        queue<vector<int>>q;
        int n=graph.size();
        q.push({0});
        while(q.empty()==false){
            vector<int> temp=move(q.front());
            q.pop();
            int node=temp.back();
            if(node==n-1){
                res.push_back(temp);
                continue;
            }
            for(int child:graph[node]){
                temp.push_back(child);
                q.push(temp);
                temp.pop_back();
            }
        }
        return res;
    }
};