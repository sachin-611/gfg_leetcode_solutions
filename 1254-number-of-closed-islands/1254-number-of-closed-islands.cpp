class Solution {
public:
    bool ispos;
    void solve(vector<vector<int>>&a,int i,int j,int n, int m){
        if(i<0 or j<0 or i>=n or j>=m){
            ispos=0;
            return;
        }
        if(a[i][j]==1 or a[i][j]==2){
            return ;
        }
        a[i][j]=2;
        solve(a,i+1,j,n,m);
        solve(a,i-1,j,n,m);
        solve(a,i,j+1,n,m);
        solve(a,i,j-1,n,m);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ispos=1;
                    solve(grid,i,j,n,m);
                    ans+=ispos;
                }
            }
        }
        return ans;
    }
};