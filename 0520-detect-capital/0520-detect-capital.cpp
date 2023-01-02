class Solution {
public:
    bool detectCapitalUse(string word) {
       int cnt=0;
        for(auto i:word)
            cnt+=(i>='A' and i<='Z');
        if(cnt==word.length() || (cnt==1 and word[0]>='A' and word[0]<='Z') || cnt==0)
            return true;
        return false;
    }
};