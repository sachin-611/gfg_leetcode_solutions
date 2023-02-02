class Solution {
    bool comp(const vector<int>&a, const vector<int>&b){
        return 1;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<vector<int>>word(words.size());
        unordered_map<char,int>m;
        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
        for(int i=0;i<words.size();i++){
            word.push_back({});
            for(auto &ch:words[i]){
                ch=(m[ch]+'a');
            }
        }
        int n=words.size();
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(words[j]>words[i])
                    return false;
            }
        }
        return true;
    }
};