class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>a(s.size());
        int last=1e6,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
                last=0;
            a[i]=last++;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==c)
                last=0;
            a[i]=min(last,a[i]);
            last++;
        }
        return a;
    }
};