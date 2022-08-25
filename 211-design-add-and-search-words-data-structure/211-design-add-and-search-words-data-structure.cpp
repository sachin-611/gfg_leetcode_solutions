class WordDictionary {
public:
   vector<vector<string>>mp;
    WordDictionary() {
        vector<string>temp;
        for(int i=0;i<26;i++)
            mp.push_back(temp);
    }
    
    void addWord(string word) {
        mp[word.length()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &i:mp[word.length()])
        {
            bool flag=true;
            for(int j=0;j<word.length();j++)
            {
                if(word[j]!='.' and word[j]!=i[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */