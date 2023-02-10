class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int res=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int sz=q.size();
        if(sz==n*n or sz==0){return -1;}
        int level=0;
        pair<int,int>ok;
        while(q.empty()==false){
            sz=q.size();
            for(int ii=0;ii<sz;ii++){
                    ok=q.front();
                if(ok.first-1>=0 and grid[ok.first-1][ok.second]==0){
                    grid[ok.first-1][ok.second]=1;
                    q.push({ok.first-1,ok.second});
                }
                if(ok.second-1>=0 and grid[ok.first][ok.second-1]==0){
                    grid[ok.first][ok.second-1]=1;
                    q.push({ok.first,ok.second-1});
                }
                if(ok.first+1<n and grid[ok.first+1][ok.second]==0){
                    grid[ok.first+1][ok.second]=1;
                    q.push({ok.first+1,ok.second});
                }
                if(ok.second+1<n and grid[ok.first][ok.second+1]==0){
                    grid[ok.first][ok.second+1]=1;
                    q.push({ok.first,ok.second+1});
                }
                q.pop();
            }
            level++;
        }
        return level-1;
    }
};