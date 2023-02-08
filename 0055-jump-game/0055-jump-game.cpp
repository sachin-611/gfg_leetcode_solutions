class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return true;
        vector<int>cnts(n);
        cnts[0]=nums[0]>0;
        for(int i=0;i<n;i++){
            int &jmp=cnts[i];
            if(i==n-1 and cnts[i]==0)
                break;
            if(cnts[i]==0)
                continue;
            // cout<<i<<" "<<cnts[i]<<endl;
            for(int j=i+nums[i];j>i;j--){
                if(j>=n)
                    return true;
                if(cnts[j]!=0)
                    continue;
                cnts[j]=jmp+1;
            }
        }
        if(cnts[n-1]==0)
            return false;
        return true;
    }
};