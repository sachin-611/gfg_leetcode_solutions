class Solution {
public:
    inline bool check(char &s){
        return (s=='a' || s=='e' || s=='i' || s=='o' || s=='u');
    }
    int maxVowels(string s, int k) {
        int res=0,cur=0;
        for(int i=0;i<k and i<s.length();i++){
            if(check(s[i]))
                cur++;
        }
        res=cur;
        for(int i=k;i<s.length();i++){
            if(check(s[i]))
                cur++;
            if(check(s[i-k]))
                cur--;
            res=max(res,cur);
        }
        return res;
    }
};