class MyCalendar {
    map<int,int>ok;
public:
    MyCalendar() {
        ok.clear();
    }
    
    bool book(int c, int d) {
        auto tem=ok.lower_bound(c);
        if(tem!=ok.end()){
            int a=tem->first,b=tem->second;
            if(c<b and a<d)return false;
        }
        if(tem!=ok.begin())
        {
            tem--;
             int a=tem->first,b=tem->second;
            if(c<b and a<d)return false;
        }
        ok[c]=d;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */