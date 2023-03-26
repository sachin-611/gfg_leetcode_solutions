class Solution {
public:
    vector<long long> minOperations(vector<int>& res, vector<int>& queries) {
        // vector<int>res(nums.begin(),nums.end());
        vector<long long>pre(res.begin(),res.end());
        vector<long long>ans;
        sort(pre.begin(),pre.end());
        for(int i=1;i<res.size();i++){
            pre[i]+=pre[i-1];
        }
        int n=res.size();
        sort(res.begin(),res.end());
        for(long long i:queries){
            long long int ress=0;
            int ind=upper_bound(res.begin(),res.end(),i-1)-res.begin()-1;
            if(ind>=0){
                ress=i*(ind+1)-pre[ind];
                
            }
            int ind1=upper_bound(res.begin(),res.end(),i)-res.begin();
            if(ind1!=n){
                long long temp=(pre[n-1]-((ind1>0)?pre[ind1-1]:0))-(n-ind1)*i;
                ress+=temp;
            }
            ans.push_back(ress);
        }
        return ans;
    }
};