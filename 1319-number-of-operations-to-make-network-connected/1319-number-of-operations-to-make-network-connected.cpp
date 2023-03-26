class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>>ok(n);
        vector<bool>vis(n);
        for(auto i:connections){
            ok[i[0]].emplace_back(i[1]);
            ok[i[1]].emplace_back(i[0]);
        }
        int connec=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                connec++;
                q.push(i);
                while(!q.empty()){
                    auto temp=q.front();
                    q.pop();
                    for(auto j:ok[temp]){
                        if(!vis[j]){
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        // if(connec==1){
        //     return -1;
        // }
        return connec-1;
    }
};