class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        const int sz=arr.size();
        vector<int>vis(sz,0);
        while(q.empty()==false){
            auto &front=q.front();
            if(arr[front]==0)
                return true;
            vis[front]=1;
            if(front-arr[front]>=0 and vis[front-arr[front]]==0){
                if(arr[front-arr[front]]==0)
                    return true;
                q.push(front-arr[front]);
            }
            if(front+arr[front]<sz and vis[front+arr[front]]==0){
                if(arr[front+arr[front]]==0)
                    return true;
                q.push(front+arr[front]);
            }
            q.pop();
        }
        return false;
    }
};