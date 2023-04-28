//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool in_range(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &mat){
        vector<vector<int> > res(n, vector<int>(m));
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        
        queue<pair<int,int> > q;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 'W'){
                    q.push({i,j});
                    vis[i][j] = true;
                    res[i][j] = 0;
                }else if(mat[i][j] == 'N'){
                    res[i][j] = -1;
                }else{
                    res[i][j] = 1;
                }
            }
        }
        
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int row = front.first;
            int col = front.second;
            
            for(int x = 0; x < 4; ++x){
                int r = drow[x] + row;
                int c = dcol[x] + col;
                
                if(in_range(r, c, n, m) && !vis[r][c] && res[r][c] == 1){
                    res[r][c] = res[row][col] + 2;
                    vis[r][c] = true;
                    q.push({r,c});
                }
            }
        }
            
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(res[i][j] == -1 || mat[i][j] == '.') res[i][j] = 0;
                else if(res[i][j] == 1) res[i][j] = -1;
            }
        }
            
            
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends