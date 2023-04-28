class Solution {
    bool pos(string &s,string &o){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=o[i]){
                cnt++;
            }
        }
        return cnt==0 or cnt==2;
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>g(n);
        vector<int>ok(n);
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
            if(!ok[i]){
                count++;
                queue<int>q;
                q.push(i);
                while(q.empty()==false){
                    top=q.front();
                    ok[top]=1;
                    q.pop();
                    for(int &chi:g[top]){
                        if(!ok[chi]){
                            q.push(chi);
                        }
                    }
                }
            }
        }
        return count;
    }
};