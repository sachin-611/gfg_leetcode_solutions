class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>&b) {
        int n=b.size();
        sort(b.begin(),b.end());
        vector<int>pre(n);
        pre[n-1]=b[n-1][1];
        for(int i=n-2;i>=0;i--)
            pre[i]=max(pre[i+1],b[i][1]);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int in=-1;
            int low=0,high=n-1;
            while(low<=high)
            {
                int mid=(high-low)/2+low;
                if(b[mid][0]<=b[i][0])
                {
                    if(b[mid][0]==b[i][0])
                        in=mid;
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
            in++;
            if(in<n and pre[in]>b[i][1])
                cnt++;
        }
        return cnt;
    }
};