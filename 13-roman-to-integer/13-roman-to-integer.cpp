class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();)
        {
            if(s[i]=='I')
            {
                if(i+1<s.length() and s[i+1]=='X')
                    ans+=9,i+=2;
                else if(i+1<s.length() and s[i+1]=='V')
                    ans+=4,i+=2;
                else 
                    ans+=1,i+=1;
            }
            else if(s[i]=='X')
            {
                if(i+1<s.length() and s[i+1]=='L')
                    ans+=40,i+=2;
                else if(i+1<s.length() and s[i+1]=='C')
                    ans+=90,i+=2;
                else 
                    ans+=10,i+=1;   
            }
            else if(s[i]=='C')
            {
                if(i+1<s.length() and s[i+1]=='D')
                    ans+=400,i+=2;
                else if(i+1<s.length() and s[i+1]=='M')
                    ans+=900,i+=2;
                else 
                    ans+=100,i+=1;
            }
            else if(s[i]=='V')
            {
                i+=1;
                ans+=5;
            }
            else if(s[i]=='L')
            {
                i+=1;
                ans+=50;
            }
            else if(s[i]=='D')
            {
                i+=1;
                ans+=500;
            }
            else if(s[i]=='M')
            {
                i+=1;
                ans+=1000;
            }
        }
        return ans;
    }
};