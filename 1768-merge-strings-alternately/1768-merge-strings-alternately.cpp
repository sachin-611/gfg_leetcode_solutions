class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int n=word1.length(),m=word2.length();
        int i=0,j=0,cnt=0;
        while(i<n and j<m){
            if(cnt%2==0){
                res.push_back(word1[i++]);
            }else{
                res.push_back(word2[j++]);
            }
            cnt++;
        }
        while(i<n)res.push_back(word1[i++]);
        while(j<m)res.push_back(word2[j++]);
        return res;
    }
};