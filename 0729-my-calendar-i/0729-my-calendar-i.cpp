class MyCalendar {
    vector<vector<int>>ok;
public:
    MyCalendar() {
        ok.clear();
    }
    
    bool book(int start, int end) {
        if(ok.empty()){
            ok.push_back({start,end});
            return true;
        }
        for(auto i:ok){
            int a=i[0],b=i[1],c=start,d=end;
            if((c>=a and c<b) or (a>=c and a<d)){
                return false;
            }
        }        
        ok.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */