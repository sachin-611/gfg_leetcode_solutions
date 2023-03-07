class Solution {
public:
    bool join_right(int prev,int num){
        if((prev==1 or prev==4 or prev==6) and (num==1 or num==3 or num==5)){
            return true;
        }
        return false;
    }
    bool join_left(int prev,int num){
        if((prev==1 or prev==3 or prev==5) and (num==1 or num==4 or num==6)){
            return true;
        }
        return false;
    }
    bool join_up(int prev,int num){
        if((prev==2 or prev==5 or prev==6) and (num==2 or num==4 or num ==3)){
            return true;
        }
        return false;
    }
    bool join_down(int prev,int num){
        if((prev==4 or prev==3 or prev==2) and (num==5 or num==6 or num==2)){
            return true;
        }
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        pair<int,int>front;
        q.push({0,0});
        int x,y;
        int n=grid.size(),m=grid[0].size();
        while(q.empty()==false){
            front=q.front();
            x=front.first,y=front.second;
            q.pop();
            if(x==n-1 and y==m-1){
                return true;
            }
            if(y+1<m and grid[x][y+1] and join_right(grid[x][y],grid[x][y+1])){
                q.push({x,y+1});
            }
            if(y-1>=0 and grid[x][y-1] and join_left(grid[x][y],grid[x][y-1])){
                q.push({x,y-1});
            }
            if(x-1>=0 and grid[x-1][y] and join_up(grid[x][y],grid[x-1][y])){
                q.push({x-1,y});
            }
            if(x+1<n and grid[x+1][y] and join_down(grid[x][y],grid[x+1][y])){
                q.push({x+1,y});
            }
            grid[x][y]=0;
        }
        return false;
    }
};