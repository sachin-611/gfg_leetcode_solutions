class CountIntervals {
    map<pair<int,int>,int>m;
    int ans;
public:
    CountIntervals() {
        m.clear();
        ans=0;
    }
    
    void add(int left, int right) {
        pair<int,int> cur={left,right};
        auto it=m.lower_bound(cur);
        if(it!=m.begin()){
            auto pr=it;
            pr--;
            if(pr->first.second>=left)it=pr;
        }
        vector<pair<int,int>>todel;
        while(it!=m.end()){
            if(it->first.first>right)
                break;
            ans-=(it->first.second-it->first.first+1);
            cur.first=min(cur.first,it->first.first);
            cur.second=max(cur.second,it->first.second);
            todel.push_back(it->first);
            it++;
        }
        while(!todel.empty()){m.erase(todel.back());todel.pop_back();}
        ans+=(cur.second-cur.first+1);
        m[cur]++;
    }
    
    int count() {
        return ans;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */