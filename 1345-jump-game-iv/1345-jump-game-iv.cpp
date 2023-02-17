class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
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
                auto &temp=m[arr[front]];
                temp.push_back(front-1);
                temp.push_back(front+1);
                for(auto &i:temp){
                    if(i>=0 and i<n and vis[i]==0){
                        if(i==n-1)
                            return level+1;
                        q.push(i);
                        vis[i]=1;
                    }
                }
                temp.clear();
            }
            level++;
        }
        return -1;
    }
};