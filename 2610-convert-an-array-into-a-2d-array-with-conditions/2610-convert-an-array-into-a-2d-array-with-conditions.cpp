class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>a;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        while(i<n){
            int cnt=0;
            int num=nums[i];
            while(i<n and nums[i]==num){
                i++;
                cnt++;
            }
            for(int i=0;i<cnt;i++){
                if(a.size()<=i){
                    a.push_back({num});
                }else{
                    a[i].push_back(num);
                }
            }
        }
        return a;
    }
};