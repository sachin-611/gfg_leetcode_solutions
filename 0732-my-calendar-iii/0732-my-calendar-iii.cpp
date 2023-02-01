class MyCalendarThree {
    map<int,int>m;
public:
    MyCalendarThree() {
        m.clear();
    }
    
    int book(int s, int e) {
        int ans=0;
        int tot=0;
        m[s]++;
        m[e]--;
        for(auto i:m){
            tot+=i.second;
            ans=max(ans,tot);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */