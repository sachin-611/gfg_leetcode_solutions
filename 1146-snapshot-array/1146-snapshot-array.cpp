class SnapshotArray {
public:
    vector<vector<pair<int,int>>>v;
    int sna;
    SnapshotArray(int length) {
        sna=0;
        for(int i=0;i<length;i++){
            v.push_back({{0,0}});
        }
    }
    
    void set(int index, int val) {
        if(v[index].back().first==sna){
            v[index].back().second=val;
        }else{
            v[index].push_back({sna,val});
        }
    }
    
    int snap() {
        return sna++;
    }
    
    int get(int index, int snap_id) {
        int val_idx=0;
        int high=v[index].size()-1;
        int low=0;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(v[index][mid].first==snap_id){
                val_idx=mid;
                break;
            }
            else if(v[index][mid].first<snap_id){
                val_idx=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return v[index][val_idx].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */