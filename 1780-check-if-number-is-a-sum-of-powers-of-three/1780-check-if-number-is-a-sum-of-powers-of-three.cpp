#define ll long long
class Solution {
public:
    vector<ll>powers;
    bool pos(ll n,ll i)
    {
        if(i==powers.size())
            return n==0;
        if(n==0)
            return true;
        if(n<0)
            return false;
        return pos(n-powers[i],i+1)|pos(n,i+1);
    }
    bool checkPowersOfThree(ll n) {
        for(ll i=1;i<=n;i*=3)
            powers.push_back(i);
        return pos(n,0);
    }
};