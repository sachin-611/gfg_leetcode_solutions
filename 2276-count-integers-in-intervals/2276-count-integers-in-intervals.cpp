class CountIntervals {
    map<int,int>m;
    bool modified;
    int ans;
public:
    CountIntervals() {
        m.clear();
        modified=false;
        ans=0;
    }
    
    void add(int left, int right) {
        m[left]++;
        m[right+1]--;
        modified=1;
    }
    
    int count() {
        if(modified){
            int prev=0;
            int total=0;
            ans=0;
            map<int,int>temp;
            for(const auto &i:m){
                if(total==0){
                    temp[i.first]++;
                    prev=i.first;
                }
                total+=i.second;
                
                if(total==0){
                    temp[i.first]--;
                    ans+=(i.first-prev);
                }
            }
            m=temp;
        }
        modified=false;
        return ans;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */