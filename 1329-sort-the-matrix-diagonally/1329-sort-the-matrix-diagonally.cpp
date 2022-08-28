class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++)
        {
            vector<int>val;
            for(int j=0;j<mat.size();j++)
            {
                if(i+j==mat.size() || j==mat[0].size())
                    break;
                val.push_back(mat[i+j][j]);
            }
            sort(val.begin(),val.end());
            int k=0;
            for(int j=0;j<mat.size();j++)
            {
                if(i+j==mat.size() || j==mat[0].size())
                    break;
                mat[i+j][j]=val[k++];
            }
        }
        for(int i=0;i<mat[0].size();i++)
        {
            vector<int>val;
            for(int j=0;j<mat.size();j++)
            {
                if(i+j==mat[0].size() || j==mat.size())
                    break;
                val.push_back(mat[j][i+j]);
            }
            sort(val.begin(),val.end());
            int k=0;
            for(int j=0;j<mat.size();j++)
            {
                if(i+j==mat[0].size() || j==mat.size())
                    break;
                mat[j][i+j]=val[k++];
            }
        }
        return mat;
    }
};