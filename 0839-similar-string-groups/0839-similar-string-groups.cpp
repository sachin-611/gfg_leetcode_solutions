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
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        g.resize(n);
        ok.resize(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(pos(strs[i],strs[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int count=0;
                int top;
        for(int i=0;i<n;i++){
            if(ok[i]==0){
                count++;
                queue<int>q;
                q.push(i);
                while(q.empty()==false){
                    top=q.front();
                    ok[top]=1;
                    q.pop();
                    for(int &chi:g[top]){
                        if(ok[chi]==0){
                            q.push(chi);
                        }
                    }
                }
            }
        }
        return count;
    }
};