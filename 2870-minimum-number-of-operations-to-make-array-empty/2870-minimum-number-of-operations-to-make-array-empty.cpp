class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second==1)
                return -1;
            int cnt=ans;
            if(i.second%3==0 or i.second%3==2){
                ans+=i.second/3;
                ans+=(i.second%3>0?1:0);
            }else{
                ans+=i.second/3-1;
                ans+=2;
            }
        }
        return ans;
    }
};