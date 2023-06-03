class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({headId,informTime[headId]});
        int ans=0;
        while(q.empty()==false){
            auto temp=q.front();
            q.pop();
            ans=max(ans,temp.second);
            for(auto &child:adj[temp.first]){
                q.push({child,temp.second+informTime[child]});
            }
        }
        return ans;
    }
};