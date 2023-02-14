class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
		vector<vector<pair<int,int>>> graph(n);
        for(auto edge: red_edges)
            graph[edge[0]].emplace_back(edge[1],0); 
        for(auto edge: blue_edges)
            graph[edge[0]].emplace_back(edge[1],1); 
        vector<int> dist(n,-1); 
        
        queue<pair<int,int>> q;
        q.push({0,2});
        int level=0;
        set<pair<int,int>>p;
        while(!q.empty()) {
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto front = q.front();
                q.pop();
                p.insert(front);
                if(dist[front.first]==-1)
                    dist[front.first]=level;
                for(auto &child:graph[front.first]){
                    if(child.second!=front.second and p.count(child)==0){
                        q.push(child);
                    }
                }
            }
            level++;
        }
        return dist;
    }
};