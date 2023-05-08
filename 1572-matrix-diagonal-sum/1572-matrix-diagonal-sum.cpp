class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res=0,n=mat.size(),m=mat[0].size();
        for(int i=0,j=0;j<m and i<n;i++,j++){
                res+=mat[i][j];
                if(j!=m-1-j)
                    res+=mat[i][m-1-j];
        }
        return res;
    }
};