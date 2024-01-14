class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        map<char,int>m,p;
        for(auto i:word1){
            m[i]++;
        }
        for(auto j:word2){
            if(m.count(j)==0)
                return false;
            p[j]++;
        }
        map<int,int>mp;
        for(auto i:m){
            mp[i.second]++;
        }
        for(auto i:p){
            mp[i.second]--;
        }
        int cnt=0;
        for(auto i:mp){
            cnt+=i.second;
            if(cnt!=0)
                return false;
        }
        return true;
    }
};