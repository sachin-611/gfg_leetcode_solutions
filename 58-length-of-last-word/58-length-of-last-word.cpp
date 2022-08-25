class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=0,n=s.length(),last=0;
        while(i<n)
        {
            while(i<n and s[i]==' ')i++;
            int cur=0;
            while(i<n and s[i]!=' ')i++,cur++;
            if(cur)
                last=cur;
        }
        return last;
    }
};