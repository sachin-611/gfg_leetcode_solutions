class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        int ans=0;
        sort(a.begin(),a.end(),greater<int>());
        for(int times=1;times<=a.size();times++){
            int cur=0;
            int val=times;
            for(int i=0;i<a.size() and val;i++){
                cur+=a[i]*val;
                val--;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};