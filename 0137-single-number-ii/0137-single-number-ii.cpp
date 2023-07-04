class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=31;i>=0;i--){
            int cnt=0;
            for(auto &num:nums){
                if(num&(1<<i)){
                    cnt++;
                }
            }
            cnt%=3;
            if(cnt){
                res|=(1<<i);
            }
        }
        return res;
    }
};