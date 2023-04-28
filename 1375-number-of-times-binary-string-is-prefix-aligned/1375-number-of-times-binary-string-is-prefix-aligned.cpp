class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int ans=0;
        int cnt=0;
        int right=-1;
        for(int &i:flips){
            cnt++;
            right=max(right,i);
            if(right==cnt){
                ans++;
            }
        }
        return ans;
    }
};