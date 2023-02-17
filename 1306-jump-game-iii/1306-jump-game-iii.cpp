class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        const int sz=arr.size();
        vector<int>vis(sz,0);
        while(q.empty()==false){
            auto front=q.front();
            q.pop();
            if(arr[front]==0)
                return true;
            vis[front]=1;
            if(front-arr[front]>=0 and vis[front-arr[front]]==0){
                q.push(front-arr[front]);
            }
            if(front+arr[front]<sz and vis[front+arr[front]]==0){
                q.push(front+arr[front]);
            }
        }
        return false;
    }
};