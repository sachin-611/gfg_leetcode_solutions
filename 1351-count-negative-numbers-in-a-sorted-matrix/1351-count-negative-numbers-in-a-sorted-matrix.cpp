class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        int i=0,j=m-1;
        while(i<n and j>=0){
            if(grid[i][j]<0){
                cnt+=(n-i);
                j--;
            }else{
                i++;
            }
        }
        return cnt;
    }
};