class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int i=0;
        int res=0;
        for(i=0;i<cost.size();i++)
        {
            if((i+1)%3!=0)
                res+=cost[i];
        }
        return res;
    }
};