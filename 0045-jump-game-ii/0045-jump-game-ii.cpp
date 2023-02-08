class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return 0;
        vector<int>cnts(n);
        cnts[0]=0;
        for(int i=0;i<n;i++){
            int &jmp=cnts[i];
            if(cnts[i]==0 and i)
                continue;
            for(int j=i+nums[i];j>i;j--){
                if(j>=n)
                {
                    if(cnts[n-1]==0 or(cnts[n-1]>jmp+1))
                    cnts[n-1]=jmp+1;
                    continue;
                }
                if(cnts[j]!=0)
                    continue;
                cnts[j]=jmp+1;
            }
        }
        return cnts[n-1];
    }
};