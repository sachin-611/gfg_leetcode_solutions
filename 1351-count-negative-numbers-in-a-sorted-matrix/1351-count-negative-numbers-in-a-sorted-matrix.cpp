class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(auto &i:grid){
            for(auto &j:i){
                cnt+=(j<0);
            }
        }
        return cnt;
    }
};