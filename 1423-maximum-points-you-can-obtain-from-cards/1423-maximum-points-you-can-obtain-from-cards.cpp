class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        vector<int>b(n+1),c(n+1);
        for(int i=1;i<=n;i++)
        {
            b[i]=a[i-1];
            b[i]+=b[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            c[i]=a[i];
            if(i+1<=n)
                c[i]+=c[i+1];
        }
        reverse(c.begin(),c.end());
        int ans=max(b[k],c[k]);
        for(int i=0;i<=k;i++)
        {
            ans=max(ans,b[i]+c[k-i]);
        }
        return ans;
    }
};