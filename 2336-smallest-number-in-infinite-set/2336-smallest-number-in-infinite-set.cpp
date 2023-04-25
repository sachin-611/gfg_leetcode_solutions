class SmallestInfiniteSet {
public:
    set<int>s;
    int cnt;
    SmallestInfiniteSet() {
        s.clear();
        cnt=1;
    }
    
    int popSmallest() {
        if(s.empty()==false){
            int val=*s.begin();
            s.erase(s.begin());
            return val;
        }else{
            return cnt++;
        }
    }
    
    void addBack(int num) {
        if(cnt>num)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */