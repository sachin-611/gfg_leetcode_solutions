class Solution {
    map<string,vector<string>>g;
    map<string,int>ok;
    bool pos(string s,string o){
        vector<int>ok;
        for(int i=0;i<s.size();i++){
            if(s[i]!=o[i]){
                ok.push_back(i);
            }
        }
        if(ok.size()==2){
            swap(s[ok[0]],s[ok[1]]);
            return s==o;
        }
        return 0;
    }
    void dfs(string s){
        ok[s]=1;
        for(string ch:g[s]){
            if(ok.count(ch)==0){
                dfs(ch);
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and pos(strs[i],strs[j])){
                    g[strs[i]].push_back(strs[j]);
                    g[strs[j]].push_back(strs[i]);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ok.count(strs[i])==0){
                dfs(strs[i]);
                count++;
            }
        }
        return count;
    }
};