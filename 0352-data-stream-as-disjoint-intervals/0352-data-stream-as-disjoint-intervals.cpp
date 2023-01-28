class SummaryRanges {
public:
    vector<int>useds;
    set<pair<int,int>>ok;
    vector<vector<int>>get_start,get_end;
    SummaryRanges() {
        ok.clear();
        useds.resize(10000+5,-1);
        get_start.resize(10000+5);
        get_end.resize(10000+5);
    }
    
    void addNum(int value) {
        if(useds[value]==1){
            // for(int i:useds)
            //     cout<<i<<" ";
            // cout<<endl;
            cout<<value<<endl;
            return;
        }
        cout<<"ok: "<<value<<endl;
        useds[value]=1;
        if(value-1>=0 and !get_start[value-1].empty() and !get_end[value+1].empty()){
            cout<<"two"<<endl;
            int p=get_start[value-1][0];
            int q=get_end[value+1][0];
            ok.erase(ok.find({p,value-1}));
            ok.erase(ok.find({value+1,q}));
            if(get_start[value-1].empty()==false)
                get_start[value-1].pop_back();
            if(get_end[value+1].empty()==false)
                get_end[value+1].pop_back();
            ok.insert({p,q});
            get_start[q][0]=(p);
            get_end[p][0]=q;
            return;
        }
        if(value-1>=0 and !get_start[value-1].empty()){
            cout<<"Left"<<endl;
            int a=get_start[value-1][0];
            int b=get_end[a][0];
            ok.erase(ok.find({a,b}));
            ok.insert({a,value});
            get_start[value-1].pop_back();
            get_end[a][0]=value;
            get_start[value].push_back(a);
            return;
        }
        if(!get_end[value+1].empty()){
            cout<<"Right"<<endl;
            int a=value+1;
            int b=get_end[a][0];
            ok.erase(ok.find({a,b}));
            ok.insert({value,b});
            get_start[b][0]=value;
            get_end[a].pop_back();
            get_end[value].push_back(b);
            return;
        }
        ok.insert({value,value});
        get_start[value].push_back(value);
        get_end[value].push_back(value);
        cout<<value<<"ended"<<endl;
    }
    
    vector<vector<int>> getIntervals() {
        cout<<"beg"<<endl;
        vector<vector<int>>res;
        for(auto i:ok)
        {
            res.push_back({i.first,i.second});
        }
        cout<<"end"<<endl;
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */