class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto v(matrix);
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v[j][n-1-i]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=v[i][j];
            }
        }
    }
};