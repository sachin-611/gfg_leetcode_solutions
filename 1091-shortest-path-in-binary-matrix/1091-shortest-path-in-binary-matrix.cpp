class Solution {
public:
    int n;
    bool pos(int x,int y){
        return (x>=0 and y>=0 and x<n and y<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        class node{
            public:
            int x;int y;int dis;
        };
        n=grid.size();
        queue<node>q;
        if(grid[0][0]==0){
        q.push({0,0,1});
            grid[0][0]=2;
        }
        while(!q.empty()){
            auto nod=q.front();
            q.pop();
            if(nod.x==n-1 and nod.y==n-1)
                return nod.dis;
            if(pos(nod.x-1,nod.y) and grid[nod.x-1][nod.y]==0){
                grid[nod.x-1][nod.y]=2;
                q.push({nod.x-1,nod.y,nod.dis+1});
            }
            if(pos(nod.x+1,nod.y) and grid[nod.x+1][nod.y]==0){
                grid[nod.x+1][nod.y]=2;
                q.push({nod.x+1,nod.y,nod.dis+1});
            }
            if(pos(nod.x,nod.y-1) and grid[nod.x][nod.y-1]==0){
                grid[nod.x][nod.y-1]=2;
                q.push({nod.x,nod.y-1,nod.dis+1});
            }
            if(pos(nod.x,nod.y+1) and grid[nod.x][nod.y+1]==0){
                grid[nod.x][nod.y+1]=2;
                q.push({nod.x,nod.y+1,nod.dis+1});
            }
            if(pos(nod.x-1,nod.y-1) and grid[nod.x-1][nod.y-1]==0){
                grid[nod.x-1][nod.y-1]=2;
                q.push({nod.x-1,nod.y-1,nod.dis+1});
            }
            if(pos(nod.x-1,nod.y+1) and grid[nod.x-1][nod.y+1]==0){
                grid[nod.x-1][nod.y+1]=2;
                q.push({nod.x-1,nod.y+1,nod.dis+1});
            }
            if(pos(nod.x+1,nod.y-1) and grid[nod.x+1][nod.y-1]==0){
                grid[nod.x+1][nod.y-1]=2;
                q.push({nod.x+1,nod.y-1,nod.dis+1});
            }
            if(pos(nod.x+1,nod.y+1) and grid[nod.x+1][nod.y+1]==0){
                grid[nod.x+1][nod.y+1]=2;
                q.push({nod.x+1,nod.y+1,nod.dis+1});
            }
        }
        return -1;
    }
};