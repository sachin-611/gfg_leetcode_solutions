class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        const int sz=arr.size();
        vector<int>vis(sz,0);
        while(q.empty()==false){
            int &front=q.front();
            int &val=arr[front];
            if(val==0)
                return true;
            vis[front]=1;
            if(front-val>=0 and vis[front-val]==0){
                if(arr[front-val]==0)
                    return true;
                q.push(front-val);
            }
            if(front+val<sz and vis[front+val]==0){
                if(arr[front+val]==0)
                    return true;
                q.push(front+val);
            }
            q.pop();
        }
        return false;
    }
};