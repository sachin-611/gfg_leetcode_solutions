class Solution {
public:
        int mod=1e9+7;
    long long bin(int b){
        long long res=1;
        long long a=2;
        while(b){
            if(b%2){
                res=(res*a)%mod;
            }
            b/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    long long numSubseq(vector<int>& a, int tar) {
        sort(a.begin(),a.end());
        long long res=0;
        int l=0,h=a.size()-1;
        while(l<=h){
            if(a[l]+a[h]<=tar){
                res=(res+bin(h-l))%mod;
                l++;
            }else{
                h--;
            }
        }
        return res;
    }
};