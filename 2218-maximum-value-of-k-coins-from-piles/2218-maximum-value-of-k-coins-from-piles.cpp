class Solution {
public:
    int dp[1001][2001];
    int maxValueOfCoins(vector<vector<int>>& piles, int k,int i=0) {
        if(i==piles.size()){
            return 0;
        }
        if(i==0){
            memset(dp,-1,sizeof(dp));
        }
        if(k==0){
            return 0;
        }
        int &res=dp[i][k];
        if(res!=-1){
            return res;
        }
        int cnt=0;
        int total=0;
        for(int &j:piles[i]){
            cnt++;
            total+=j;
            if(cnt<=k){
                res=max(res,maxValueOfCoins(piles,k-cnt,i+1)+total);
            }else{
                break;
            }
        }
        res=max(res,maxValueOfCoins(piles,k,i+1));
        return res;
    }
};