int get_distance(const vector<int>&a){
    return a[0]*a[0]+a[1]*a[1];
}
class point{
    public:
    bool operator()(const vector<int>&a,const vector<int>&b){
        return get_distance(a)<get_distance(b);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,point>p;
        for(auto &i:points){
            if(p.size()<k){
                p.push(i);
            }else{
                int cur=get_distance(i);
                int tops=get_distance(p.top());
                if(cur<tops){
                    p.pop();
                    p.push(i);
                }
            }
        }
        vector<vector<int>>res;
        while(p.empty()==false){
            res.push_back(p.top());
            p.pop();
        }
        return res;
    }
};