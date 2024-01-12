class Solution {
public:
    bool isVowel(char c){
        const static string s="aeiouAEIOU";
        if(s.find(c)!=string::npos)
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int first=0,second=0,n=s.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(isVowel(s[i])){
                    first++;
                }
            }else{
                if(isVowel(s[i])){
                    second++;
                }
            }
        }
        return first==second;
    }
};