#define ll long long
class Solution {
public:
    bool checkPowersOfThree(ll n) {
        vector<ll>powers;
        for(ll i=1;i<=n;i*=3)
            powers.push_back(i);
        ll ans=0;
        while(ans<n and !powers.empty())
        {
            if(ans+powers.back()<=n)
            {
                ans+=powers.back();
                powers.pop_back();
            }
            else
                powers.pop_back();
        }
        return ans==n;
    }
};