class Solution {
public:
    bool wordPattern(string p, string s) {
        int i=0,j=0;
        int n=p.length(),m=s.length();
        unordered_map<char,string>mp;
        unordered_map<string,char>pm;
        while(j<n)
        {
            string temp="";
            while(i<m and s[i]!=' ')
                temp.push_back(s[i++]);
            i++;
            if(temp=="")
                return false;
            if((mp.count(p[j]) and mp[p[j]]!=temp) or(pm.count(temp) and pm[temp]!=p[j]))
                return false;
            mp[p[j]]=temp;
            pm[temp]=p[j];
            j++;
        }
        if(i<m)
            return false;
        return true;
    }
};