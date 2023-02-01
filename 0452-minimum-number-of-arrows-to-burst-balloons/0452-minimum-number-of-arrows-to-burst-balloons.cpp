bool comp(const vector<int>&a,const vector<int>&b){
    return a[1]<b[1];
    if(a[0]!=b[0])
        return a[0]<b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int ans=0;
        int i=0,n=points.size();
        // for(auto i:points){
        //     cout<<"{"<<i[0]<<" "<<i[1]<<"} ";
        // }
        //     cout<<endl;
        while(i<n){
            int last=points[i][1];
            ans++;
            while(i<n and points[i][1]>=last and points[i][0]<=last)
                i++;
        }
        return ans;
    }
};