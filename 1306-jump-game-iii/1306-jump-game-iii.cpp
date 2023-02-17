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
            int diff=front-val;
            int sum=front+val;
            if(val==0)
                return true;
            vis[front]=1;
            if(diff>=0 and vis[diff]==0){
                if(arr[diff]==0)
                    return true;
                q.push(diff);
            }
            if(sum<sz and vis[sum]==0){
                if(arr[sum]==0)
                    return true;
                q.push(sum);
            }
            q.pop();
        }
        return false;
    }
};