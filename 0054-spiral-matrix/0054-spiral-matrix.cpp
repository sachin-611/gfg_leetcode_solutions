class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int x[]={0,1,0,-1};
        int y[]={1,0,-1,0};
        int k=0,i=0,j=0;
        res.push_back({matrix[0][0]});
        matrix[0][0]=101;
        int n=matrix.size(),m=matrix[0].size();
        for(int item=1;item<n*m;item++){
            if(i+x[k]>=n or j+y[k]>=m or i+x[k]<0 or j+y[k]<0 or matrix[i+x[k]][j+y[k]]==101){
                k++;
                k%=4;
            }
            // cout<<k<<" ";
            i+=x[k];
            j+=y[k];
            res.push_back(matrix[i][j]);
            matrix[i][j]=101;
        }
        return res;
    }
};