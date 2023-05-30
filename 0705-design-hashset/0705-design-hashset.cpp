class MyHashSet {
public:
    unordered_set<int>m;
    MyHashSet() {
        m.clear();
    }
    
    void add(int key) {
        m.insert(key);
    }
    
    void remove(int key) {
        if(m.count(key))
        m.erase(key);
    }
    
    bool contains(int key) {
        return m.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */