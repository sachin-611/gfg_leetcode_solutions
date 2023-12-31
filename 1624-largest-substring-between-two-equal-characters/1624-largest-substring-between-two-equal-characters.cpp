class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<vector<int>>a(27);
        for(int i=0;i<s.size();i++){
            a[(s[i]-'a')].push_back(i);
        }
        int res=-1;
        for(auto &i:a){
            if(i.empty()==false and i.size()>1){
                res=max(res,(i[i.size()-1]-i[0]+1)-2);
            }
        }
        return res;
    }
};
