class Solution {
public:
    int dp[501][501];
    int minInsertions(string &s,int i=0,int j=505) {
        if(j>s.size()){
            //initial phase
            j=s.length()-1;
            memset(dp,-1,sizeof(dp));
        }
        if(i>=j)
            return 0;
        int &res=dp[i][j];
        if(res!=-1)
            return res;
        if(s[i]==s[j]){
            return res=minInsertions(s,i+1,j-1);
        }else{
            return res=min(minInsertions(s,i+1,j),minInsertions(s,i,j-1))+1;
        }
    }
};