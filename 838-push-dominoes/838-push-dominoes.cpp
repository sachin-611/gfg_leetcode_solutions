int force[100001];
class Solution {
public:
    string pushDominoes(string s) {
        int va=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='R')
                va=s.size();
            else if(s[i]=='L')
                va=0;
            else
                va=max(0,va-1);
            force[i]=va;
        }
        va=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='L')
                va=s.size();
            else if(s[i]=='R')
                va=0;
            else
                va=max(va-1,0);
            force[i]-=va;
        }
        for(int i=0;i<s.size();i++)
        {
            if(force[i]>0)
                s[i]='R';
            else if(force[i]<0)
                s[i]='L';
            else
                s[i]='.';
        }
        return s;
    }
};