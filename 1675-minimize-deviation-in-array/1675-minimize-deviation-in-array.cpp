class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mini=INT_MAX,diff=INT_MAX;
        for(auto i:nums){
            if(i&1){
                i=i<<1;
            }
            pq.push(i);
            mini=min(mini,i);
        }
        while(pq.empty()==false){
            int top=pq.top();
            // cout<<top<<" "<<mini<<" "<<diff<<endl;
            pq.pop();
            diff=min(diff,top-mini);
            if(top%2==0){
                pq.push(top>>1);
                mini=min(mini,top>>1);
            }
            if(top&1){
                pq.push(top);
                break;
            }
        }
        return min(diff,pq.top()-mini);
    }
};