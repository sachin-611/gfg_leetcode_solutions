class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>m;
        int n=words.size();
        for(int i=0;i<26;i++){
            m[order[i]]=i;
        }
        for(int i=0;i<n;i++){
            for(auto &ch:words[i]){
                ch=(m[ch]+'a');
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(words[j]>words[i])
                    return false;
            }
        }
        return true;
    }
};