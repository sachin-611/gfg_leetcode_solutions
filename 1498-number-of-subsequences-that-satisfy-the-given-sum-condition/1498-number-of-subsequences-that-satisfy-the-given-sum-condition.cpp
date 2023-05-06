class Solution {
public:
        int mod=1e9+7;
    int numSubseq(vector<int>& a, int tar) {
        vector<int>pre={1};
        for(int i=1;i<a.size();i++){
            pre.push_back((pre.back()<<1)%mod);
        }
        sort(a.begin(),a.end());
        int res=0;
        int l=0,h=a.size()-1;
        while(l<=h){
            if(a[l]+a[h]<=tar){
                res=(res+pre[(h-l)])%mod;
                l++;
            }else{
                h--;
            }
        }
        return res;
    }
};