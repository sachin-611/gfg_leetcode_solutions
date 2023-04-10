class Solution {
public:
    vector<vector<int>>g;
    vector<int>vis;
    vector<int>fvis;
    vector<vector<int>>oks;
    string col;
    int res=-1;
    int finala;
    
    void cal(int node){
        vis[node]=1;
        fvis[node]=1;
        auto &m=oks[node];
            for(int &i:g[node]){
                if(vis[i]==0){
                    if(!fvis[i]){
                        cal(i);
                    }
                    int cnt=0;
                    for(auto &jk:oks[i]){
                        m[cnt]=max(jk,m[cnt]);
                        cnt++;
                    }
                }else{
                    finala=-1;
                }
                if(finala==-1){
                    return;
                }
            }
        m[col[node]-'a']++;
        for(auto &i:m){
            res=max(res,i);
        }
        vis[node]=0;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        if(edges.empty()){
            return 1;
        }
        
        finala=1;
        g.resize(colors.size());
        oks.resize(colors.size(),vector<int>(26,0));
        vis.resize(colors.size());
        fvis.resize(colors.size());
        col=colors;
        
        for(auto &i:edges){
            g[i[0]].push_back(i[1]);
        }
        
        for(int i=0;i<colors.size();i++){
            if(fvis[i]==0){
                cal(i);
            }
        }
        if(finala==-1)return finala;
        return res;
    }
};