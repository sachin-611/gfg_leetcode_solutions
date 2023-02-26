class Solution {
public:
    vector<vector<int>>dp;
    int minDistance(string word1, string word2,int i=0,int j=0) {
        int n=word1.size(),m=word2.size();
        if(i==0 and j==0){
            dp.resize(500,vector<int>(500,-1));
        }
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=minDistance(word1,word2,i+1,j+1);
        }
        else{
            int mini=minDistance(word1,word2,i+1,j);
            mini=min(mini,minDistance(word1,word2,i,j+1));
            mini=min(mini,minDistance(word1,word2,i+1,j+1));
            return dp[i][j]=mini+1;
        }
    }
};