class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>&b) {
        int n=b.size();
        sort(b.begin(),b.end());
        vector<int>pre(n);
        vector<int>a(n);
        for(int i=0;i<n;i++)a[i]=b[i][0];
        pre[n-1]=b[n-1][1];
        for(int i=n-2;i>=0;i--)
            pre[i]=max(pre[i+1],b[i][1]);
        int cnt=0;
        // for(int i:a)
        //     cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++)
        {
            int in=upper_bound(a.begin(),a.end(),a[i])-a.begin();
            if(in<n and pre[in]>b[i][1])
                cnt++;
        }
        return cnt;
    }
};