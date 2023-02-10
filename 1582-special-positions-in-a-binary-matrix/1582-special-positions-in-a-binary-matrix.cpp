class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),ans=0;
        vector<int>cnt(n),cn(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    continue;
                cnt[i]++;
                cn[j]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    continue;
                if(cnt[i]==1 and cn[j]==1)
                    ans++;
            }
        }
        return ans;
    }
};