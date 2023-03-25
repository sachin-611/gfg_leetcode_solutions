class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,1);
        vector<vector<int>>g(n);
        for(auto &i:edges){
            g[i[0]].emplace_back(i[1]);
            g[i[1]].emplace_back(i[0]);
        }
        int tot=n;
        long long res=0;
        long long sz=0;
                queue<int>q;
        for(int i=0;i<n;i++){
            if(vis[i]){
                sz=0;
                q.push(i);
                vis[i]=0;
                while(!q.empty()){
                    ++sz;
                    int temp=q.front();
                    q.pop();
                    for(int &child:g[temp]){
                        if(vis[child]){
                            vis[child]=0;
                            q.push(child);
                        }
                    }
                }
                res=res+(tot-sz)*sz;
                tot=tot-sz;
            }
        }
        return res;
    }
};