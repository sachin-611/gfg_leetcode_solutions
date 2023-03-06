class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mini=nums[0]*2,diff=1e9+5,ans=-1;
        for(auto i:nums){
            if(i%2){
                i*=2;
            }
            pq.push(i);
            // cout<<i<<" ";
            mini=min(mini,i);
        }
        while(pq.empty()==false){
            int top=pq.top();
            // cout<<top<<" "<<mini<<" "<<diff<<endl;
            pq.pop();
            diff=min(diff,top-mini);
            if(top%2==0){
                pq.push(top/2);
                mini=min(mini,top/2);
            }
            if(top%2){
                pq.push(top);
                break;
            }
        }
        return min(diff,pq.top()-mini);
    }
};