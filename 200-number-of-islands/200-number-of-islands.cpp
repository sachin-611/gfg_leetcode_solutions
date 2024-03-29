class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& arr){
        if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || arr[i][j]=='0' || arr[i][j]=='a')         {
            return;   
        }
        arr[i][j]='a';
        dfs(i+1,j,arr);
        dfs(i,j+1,arr);
        dfs(i-1,j,arr);
        dfs(i,j-1,arr);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};