class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>vis(n);
        vector<vector<int>>g(n);
        for(auto &i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        int tot=n;
        long long res=0;
        for(int i=0;i<n;i++){
            int sz=0;
            if(vis[i]==0){
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(q.empty()==false){
                    sz++;
                    int temp=q.front();
                    q.pop();
                    for(int child:g[temp]){
                        if(vis[child]==0){
                            vis[child]=1;
                            q.push(child);
                        }
                    }
                }
                long long rem=tot-sz;
                res=res+rem*sz;
                tot-=sz;
            }
        }
        return res;
    }
};