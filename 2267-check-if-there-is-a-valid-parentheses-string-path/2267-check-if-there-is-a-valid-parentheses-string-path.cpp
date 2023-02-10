class Solution {
    int s;
    vector<vector<vector<int>>>dp;
public:
    bool hasValidPath(vector<vector<char>>& grid,int i=0,int j=0) {
        if(i==0 and j==0){
            dp.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid.size()+grid[0].size(),-1)));
        }
        if(i>=grid.size() or j>=grid[0].size())
            return false;
        if(i==grid.size()-1 and j==grid[0].size()-1){
            return s==1 and grid[i][j]==')';
        }
        if(dp[i][j][s]!=-1)
            return dp[i][j][s];
        if(grid[i][j]=='('){
            s++;
        }
        else if(s==0){
            return dp[i][j][s]=false;
        }
        else{
            s--;
        }
        bool p1=hasValidPath(grid,i+1,j);
        if(p1)
            return dp[i][j][s]= true;
        
        bool p2=hasValidPath(grid,i,j+1);
        if(p2)
            return dp[i][j][s]=true;
        if(grid[i][j]=='('){
            s--;
        }
        else{
            s++;
        }
        return dp[i][j][s]=false;
    }
};