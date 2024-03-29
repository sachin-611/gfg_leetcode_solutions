class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res=0;
        unordered_set<string>ne[26];
        for(const string &str:ideas){
            ne[str[0]-'a'].insert(str.substr(1));
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                int cnt=0;
                for(const string &str:ne[i]){
                    if(ne[j].count(str))
                        cnt++;
                }
                res=res+(ne[i].size()-cnt)*(ne[j].size()-cnt);
            }
        }
        return res*2;
    }
};