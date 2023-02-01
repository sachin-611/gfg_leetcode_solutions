class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0,n=intervals.size();
        vector<vector<int>>res;
        res.push_back(intervals[i]);
        i++;
        while(i<n){
            if(intervals[i][0]>res.back()[1]){
                res.push_back(intervals[i]);
            }else{
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
            i++;
        }
        return res;
    }
};