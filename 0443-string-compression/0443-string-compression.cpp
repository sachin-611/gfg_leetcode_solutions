class Solution {
public:
    int compress(vector<char>& chars) {
        string temp="";
        vector<char>finals;
        int i=0,n=chars.size();
        while(i<n){
            char cur=chars[i];
            int cnt=0;
            while(i<n and cur==chars[i]){
                cnt++;
                i++;
            }
            finals.push_back(cur);
            if(cnt>1){
                auto oks=to_string(cnt);
                for(char &i:oks){
                    finals.push_back(i);
                }
            }
        }
        chars=finals;
        return chars.size();
    }
};