class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int cnt0=0,cnt1=0,m=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')==1)
                cnt1=1;
            if(target[i]-'0'==1)
                cnt0=1;
            if(s[i]==target[i])
                m++;
        }
        return cnt0+cnt1==2 || m==n;
    }
};