class Solution {
public:
    int n,m;
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        int c=-69,r=-69;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c=j,r=i;
                    break;
                }
            }
            if(c!=-69)
                break;
        }
        queue<vector<int>>q;
        queue<pair<int,int>>fq;
        fq.push({r,c});
        while(fq.empty()==false){
            auto front=fq.front();
            fq.pop();
            q.push({front.first,front.second,0});
            grid[front.first][front.second]=3;
            if(front.first-1>=0 and grid[front.first-1][front.second]==1){
                fq.push({front.first-1,front.second});
                grid[front.first-1][front.second]=2;
            }
            if(front.first+1<n and grid[front.first+1][front.second]==1){
                fq.push({front.first+1,front.second});
                grid[front.first+1][front.second]=2;
            }
            if(front.second-1>=0 and grid[front.first][front.second-1]==1){
                fq.push({front.first,front.second-1});
                grid[front.first][front.second-1]=2;
            }
            if(front.second+1<m and grid[front.first][front.second+1]==1){
                fq.push({front.first,front.second+1});
                grid[front.first][front.second+1]=2;
            }
        }
        int level=0;
        while(q.empty()==false){
                auto front=q.front();
                q.pop();
                int i=front[0],j=front[1];
                if((has(i-1,j) and grid[i-1][j]==1) or (has(i+1,j) and grid[i+1][j]==1) or (has(i,j-1) and grid[i][j-1]==1) or (has(i,j+1) and grid[i][j+1]==1)){
                    return front[2];
                }
                if(has(i-1,j) and grid[i-1][j]==0){
                    q.push({i-1,j,front[2]+1});
                    grid[i-1][j]=2;
                }
                if(has(i+1,j) and grid[i+1][j]==0){
                    q.push({i+1,j,front[2]+1});
                    grid[i+1][j]=2;
                }
                if(has(i,j-1) and grid[i][j-1]==0){
                    q.push({i,j-1,front[2]+1});
                    grid[i][j-1]=2;
                }
                if(has(i,j+1) and grid[i][j+1]==0){
                    q.push({i,j+1,front[2]+1});
                    grid[i][j+1]=2;
                }
        }
        return level;
    }
    inline bool has(int i,int j){
        return (i>=0 and j>=0 and j<m and i<n) ;
    }
};