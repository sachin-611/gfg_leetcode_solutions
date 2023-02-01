bool comp(const vector<int>&a,const vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int ans=0;
        int i=0,n=points.size();
        while(i<n){
            int last=points[i][1];
            ans++;
            while(i<n and points[i][1]>=last and points[i][0]<=last)
                i++;
        }
        return ans;
    }
};