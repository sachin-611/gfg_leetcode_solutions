class Solution {
public:
    bool check(char &s){
        return (s=='a' || s=='e' || s=='i' || s=='o' || s=='u');
    }
    int maxVowels(string s, int k) {
        int res=0,cur=0;
        for(int i=0;i<s.length();i++){
            if(check(s[i]))
                cur++;
            if(i-k>=0 and check(s[i-k]))
                cur--;
            res=max(res,cur);
        }
        return res;
    }
};