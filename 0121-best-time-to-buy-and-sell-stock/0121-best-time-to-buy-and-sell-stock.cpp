class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, maxi=0;
        for(int i=(int)prices.size()-1;i>=0;i--){
            ans=max(maxi-prices[i],ans);
            maxi=max(maxi,prices[i]);
        }
        return ans;
    }
};