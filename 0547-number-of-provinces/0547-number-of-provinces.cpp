class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                queue<int>q;
                q.push(i);
                while(q.empty()==false){
                    auto front=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(vis[j]==0 and isConnected[front][j]==1){
                            q.push(j);
                            vis[j]=1;
                        }
                    }
                }
                cnt++;
            }
        }
        return cnt;
    }
};