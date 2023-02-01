bool comp(const vector<int>&a,const vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int i=0,n=intervals.size();
        int ans=0;
        while(i<n){
            int cnt=0;
            int last=intervals[i][1];
            i++;
            while(i<n and last<=intervals[i][1] and last>intervals[i][0]){
                i++;
                cnt++;
            }
            ans+=cnt;
        }
        return ans;
    }
};