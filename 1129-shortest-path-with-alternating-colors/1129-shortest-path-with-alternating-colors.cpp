class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
		vector<vector<pair<int,int>>> graph(n);
        for(auto edge: red_edges)
            graph[edge[0]].emplace_back(edge[1],0); 
        for(auto edge: blue_edges)
            graph[edge[0]].emplace_back(edge[1],1); 
        vector<int> dist(n,-1); 
        
        queue<vector<int>> q;
        q.push({0,2});
        int level=0;
        set<vector<int>>p;
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto front = q.front();
                q.pop();
                p.insert(front);
                if(dist[front[0]]==-1)
                    dist[front[0]]=level;
                for(auto child:graph[front[0]]){
                    if(child.second!=front[1] and p.count({child.first,child.second})==0){
                        q.push({child.first,child.second});
                    }
                }
            }
            level++;
        }
        return dist;
    }
};