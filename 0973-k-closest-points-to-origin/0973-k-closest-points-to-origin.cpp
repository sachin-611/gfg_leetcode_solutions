int get_distance(const vector<int>&a){
    return a[0]*a[0]+a[1]*a[1];
}
class point{
    public:
    bool operator()(const vector<int>&a,const vector<int>&b){
        return get_distance(a)>get_distance(b);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        make_heap(points.begin(),points.end(),point());
        for(int i=0;i<k;i++){
            res.push_back(points[0]);
            pop_heap(points.begin(),points.end(),point());
            points.pop_back();
        }
        return res;
    }
};