struct point{
    bool operator()(const vector<int>&a,const vector<int>&b){
        return a[0]*a[0]+a[1]*a[1]>b[0]*b[0]+b[1]*b[1];
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res(k);
        make_heap(points.begin(),points.end(),point());
        for(int i=0;i<k;i++){
            res[i]=(points[0]);
            pop_heap(points.begin(),points.end(),point());
            points.pop_back();
        }
        return res;
    }
};