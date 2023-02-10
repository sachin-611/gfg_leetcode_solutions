class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>res(mat);
        int n=mat.size(),m=mat[0].size(),level=0,sz;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                    q.push({i,j});
            }
        }
        pair<int,int>ok;
        while(q.empty()==false){
            sz=q.size();
            level++;
            for(int i=0;i<sz;i++){
                ok=q.front();
                if(ok.first-1>=0 and mat[ok.first-1][ok.second]==1){
                    mat[ok.first-1][ok.second]=0;
                    res[ok.first-1][ok.second]=level;
                    q.push({ok.first-1,ok.second});
                }
                if(ok.second-1>=0 and mat[ok.first][ok.second-1]==1){
                    mat[ok.first][ok.second-1]=0;
                    res[ok.first][ok.second-1]=level;
                    q.push({ok.first,ok.second-1});
                }
                if(ok.first+1<n and mat[ok.first+1][ok.second]==1){
                    mat[ok.first+1][ok.second]=0;
                    res[ok.first+1][ok.second]=level;
                    q.push({ok.first+1,ok.second});
                }
                if(ok.second+1<m and mat[ok.first][ok.second+1]==1){
                    mat[ok.first][ok.second+1]=0;
                    res[ok.first][ok.second+1]=level;
                    q.push({ok.first,ok.second+1});
                }
                q.pop();
            }
        }
        return res;
    }
};