class Solution {
        queue<vector<int>>q;
    int bfs(vector<vector<int>>&grid){
        int level=0;
        set<pair<int,int>>used;
        int n=grid.size();
        while(q.empty()==false){
            int sz=q.size();
            for(int ii=0;ii<sz;ii++){
                vector<int>&ok=q.front();
                used.insert({ok[0],ok[1]});
                if(ok[0]-1>=0 and grid[ok[0]-1][ok[1]]==0){
                    grid[ok[0]-1][ok[1]]=1;
                    q.push({ok[0]-1,ok[1]});
                }
                if(ok[1]-1>=0 and grid[ok[0]][ok[1]-1]==0){
                    grid[ok[0]][ok[1]-1]=1;
                    q.push({ok[0],ok[1]-1});
                }
                if(ok[0]+1<n and grid[ok[0]+1][ok[1]]==0){
                    grid[ok[0]+1][ok[1]]=1;
                    q.push({ok[0]+1,ok[1]});
                }
                if(ok[1]+1<n and grid[ok[0]][ok[1]+1]==0){
                    grid[ok[0]][ok[1]+1]=1;
                    q.push({ok[0],ok[1]+1});
                }
                q.pop();
            }
            level++;
        }
        return level-1;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==n*n or q.empty()){
            return -1
        ;}
        return bfs(grid);
    }
};