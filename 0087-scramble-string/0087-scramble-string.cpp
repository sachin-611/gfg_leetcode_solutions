class Solution {
public:
bool rec(string s1, string s2,map<string,bool>&dp)
{
     if (s1.size()==1) return s1==s2;
     if (s1==s2) return true;
     string str=s1+"*"+s2;
     if (dp.count(str)) return dp[str];
     int n=s1.size();
          for (int i=1;i<n;i++)
     {
         if ((rec(s1.substr(0,i),s2.substr(0,i),dp) && rec(s1.substr(i),s2.substr(i),dp)) || 
         (rec(s1.substr(0,i),s2.substr(n-i),dp) && rec(s1.substr(i),s2.substr(0,n-i),dp))) 
         {
             return dp[str]=true;
         }
     }
     return dp[str]=false;
}
    bool isScramble(string s1, string s2) 
    {
        map<string,bool>dp;
        return rec(s1,s2,dp);
    }
};