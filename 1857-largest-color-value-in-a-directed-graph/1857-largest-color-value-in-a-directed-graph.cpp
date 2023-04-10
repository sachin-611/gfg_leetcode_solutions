class Solution {
public:
    vector<vector<int>>g;
    vector<int>vis;
    vector<int>fvis;
    vector<unordered_map<int,int>>oks;
    string col;
    int res=-1;
    int finala;
    unordered_map<int,int> cal(int node){
        vis[node]=1;
        fvis[node]=1;
        unordered_map<int,int>m;
            for(int &i:g[node]){
                if(vis[i]==0){
                    if(!fvis[i]){
                        
                        auto tems=cal(i);
                        for(auto jk : tems){
                            m[jk.first]=max(jk.second,m[jk.first]);
                        }
                    }
                    else{
                        auto tem=oks[i];
                        for(auto jk:tem){
                            m[jk.first]=max(jk.second,m[jk.first]);
                        }
                    }
                }else{
                    finala=-1;
                }
            }
        m[col[node]]++;
        //     cout<<"for node:"<<node<<endl;
        for(auto &i:m){
            // cout<<char(i.first)<<" "<<i.second<<endl;;
            res=max(res,i.second);
        }
        // cout<<endl;
        oks[node]=m;
        vis[node]=0;
        return m;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        if(edges.empty()){
            return 1;
        }
        finala=1;
        g.resize(colors.size());
        oks.resize(colors.size());
        vis.resize(colors.size());
        fvis.resize(colors.size());
        col=colors;
        for(auto &i:edges){
            // if(i[0]!=i[1]){
                g[i[0]].push_back(i[1]);
            // }
        }
        
        for(int i=0;i<colors.size();i++){
            if(fvis[i]==0){
                unordered_map<int,int>m;
                cal(i);
            }
        }
        if(finala==-1)return finala;
        return res;
    }
};