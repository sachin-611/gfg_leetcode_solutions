class Solution {
public:
    long long numWays(string s) {
        int n=s.size();
        int ones=0;
        int mod=1e9+7;
        for(auto &i:s){
            if(i=='1'){
                ++ones;
            }
        }
        if(ones==0){
            int ans=0;
            for(int i=1;i<n;i++){
                int rem=n-i;
                if(rem-1>0){
                    ans+=rem-1;
                    ans%=mod;
                }
            }
            return ans;
        }
        if(ones%3!=0){
            return 0;
        }
        vector<int>cnt(n);
        cnt[0]=(s[0]=='1');
        for(int i=1;i<n;i++){
            cnt[i]=cnt[i-1]+(s[i]=='1');
        }
        
        int one=ones/3;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(cnt[i]!=one)continue;
            int temp1=(upper_bound(cnt.begin(),cnt.end(),one*2)-cnt.begin());
            int temp2=(lower_bound(cnt.begin(),cnt.end(),one*2)-cnt.begin());
            ans=((ans+(temp1-temp2)%mod)%mod+mod)%mod;
            // cout<<i<<" "<<one<<" "<<cnt[i]<<" "<<temp1<<" "<<temp2<<endl;
        }
        return ans;
    }
};