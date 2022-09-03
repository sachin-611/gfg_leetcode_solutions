        vector<vector<int>>res,
        po(201,vector<int>(201)),
        vis(201,vector<int>(201));
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        res.clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                po[i][j]=vis[i][j]=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0)
            {
                dfs(i,0,heights);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(vis[0][i]==0)
            {
                dfs(0,i,heights);
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vis[i][j]=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i][m-1]==0)
            {
                dfs(i,m-1,heights);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(vis[n-1][i]==0)
            {
                dfs(n-1,i,heights);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(po[i][j]==2)
                    res.push_back({i,j});
            }
        }
        // debug(po);
        return res;
    }
    void dfs(int f,int s,vector<vector<int>>&heights)
    {
        (po[f][s]==0?po[f][s]=1:po[f][s]=2);
        vis[f][s]=1;
        if(s+1<heights[0].size() and vis[f][s+1]==0 and heights[f][s]<=heights[f][s+1]){
                        dfs(f,s+1,heights);
        }
        if(s-1>=0 and vis[f][s-1]==0 and heights[f][s]<=heights[f][s-1]){
                        dfs(f,s-1,heights);
        }
        if(f-1>=0 and vis[f-1][s]==0 and heights[f][s]<=heights[f-1][s]){
                        dfs(f-1,s,heights);
        }
        if(f+1<heights.size() and vis[f+1][s]==0 and heights[f][s]<=heights[f+1][s]){
                        dfs(f+1,s,heights);
        }
    }
};