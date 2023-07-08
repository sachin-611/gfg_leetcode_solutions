class Solution {
public:
    long long putMarbles(vector<int>& weight, int k) {
        int n=weight.size();
        long long maxi=weight[0]+weight[n-1];
        long long mini=weight[0]+weight[n-1];
        priority_queue<int,vector<int>,greater<int>>mins;
        priority_queue<int>maxs;
        for(int i=1;i<n;i++)
        {
            mins.push(weight[i]+weight[i-1]);
            maxs.push(weight[i]+weight[i-1]);
        }
        for(int j=1;j<k;j++)
        {
            mini+=mins.top();
            maxi+=maxs.top();
            mins.pop();
            maxs.pop();
        }
        // cout<<q.top();
        return maxi-mini;
    }
};