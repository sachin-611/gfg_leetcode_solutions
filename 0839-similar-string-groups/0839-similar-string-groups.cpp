class Solution {
    vector<vector<int>>g;
    vector<int>ok;
    bool pos(string &s,string &o){
        vector<int>ok;
        for(int i=0;i<s.size();i++){
            if(s[i]!=o[i]){
                ok.push_back(i);
            }
        }
        if(ok.size()==2){
            return s[ok[1]]==o[ok[0]];
        }
        return ok.empty();
    }
    void dfs(int ind){
        ok[ind]=1;
        for(int ch:g[ind]){
            if(ok[ch]==0){
                dfs(ch);
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        g.resize(n);
        ok.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and pos(strs[i],strs[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ok[i]==0){
                dfs(i);
                count++;
            }
        }
        return count;
    }
};