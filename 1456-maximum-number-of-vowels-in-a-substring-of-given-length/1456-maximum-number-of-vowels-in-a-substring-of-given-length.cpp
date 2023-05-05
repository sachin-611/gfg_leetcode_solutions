class Solution {
public:
    inline bool check(char &s){
        return (s=='a' || s=='e' || s=='i' || s=='o' || s=='u');
    }
    int maxVowels(string &s, int &k) {
        int res=0,cur=0,n=s.length();
        for(int i=0;i<n;i++){
            if(check(s[i]))
                cur++;
            if(i-k>=0 and check(s[i-k]))
                cur--;
            res=max(res,cur);
        }
        return res;
    }
};