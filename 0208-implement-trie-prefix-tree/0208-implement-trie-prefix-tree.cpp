class Trie {
public:
    unordered_set<string>s,h;
    Trie() {
        s.clear();
        h.clear();
    }
    
    void insert(string word) {
        h.insert(word);
        string temp="";
        for(auto &ch : word){
            temp.push_back(ch);
            s.insert(temp);
        }
    }
    
    bool search(string word) {
        return h.count(word);
    }
    
    bool startsWith(string prefix) {
        return s.count(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */