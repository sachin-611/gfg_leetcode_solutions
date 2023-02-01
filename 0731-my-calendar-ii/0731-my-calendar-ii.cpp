class MyCalendarTwo {
    map<int,int>m;
public:
    MyCalendarTwo() {
        m.clear();
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int total=0;
        for(auto i:m){
            total+=i.second;
            if(total>=3){
                m[start]--;
                m[end]++;
                if(m[start]==0){
                    m.erase(start);
                }
                if(m[end]==0){
                    m.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */