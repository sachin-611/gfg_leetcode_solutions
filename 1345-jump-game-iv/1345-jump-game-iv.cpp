class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,unordered_set<int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].insert(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n);
        int level=0;
        while(q.empty()==false){
            int sz=q.size();
            while(sz--){
                auto front=q.front();
                q.pop();
                if(front==n-1){
                    return level;
                }
                vis[front]=1;
                // auto &temp=m[arr[front]];
                for(auto &i:m[arr[front]]){
                    if(vis[i]==0){
                        q.push(i);
                        vis[i]=1;
                    }
                }
                m.erase(arr[front]);
                if(front-1>=0 and vis[front-1]==0){
                    q.push(front-1);
                    vis[front-1]=1;
                }
                if(front+1<n and vis[front+1]==0){
                    q.push(front+1);
                    vis[front+1]=1;
                }
            }
            level++;
        }
        return -1;
    }
};