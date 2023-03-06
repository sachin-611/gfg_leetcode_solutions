class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int lc=numsDivide[0];
        for(int i=0;i<numsDivide.size();i++){
            lc=__gcd(lc,numsDivide[i]);
        }
        // cout<<lc<<endl;
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int &i:nums){
            if(i>lc)
                break;
            if(lc%i==0){
                return cnt;
            }
            cnt++;
        }
        return -1;
    }
};