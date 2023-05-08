class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res=0;
        for(int i=0,j=0;j<mat[0].size() and i<mat.size();i++,j++){
                res+=mat[i][j];
                if(j!=mat[0].size()-1-j)
                    res+=mat[i][mat[0].size()-1-j];
        }
        return res;
    }
};