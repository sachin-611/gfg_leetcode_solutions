class Solution {
public:
    string reverseWords(string s) {
        int i=0,n=s.length();
        string ans="";
        while(i<n)
        {
            string temp="";
            while(i<n and s[i]!=' ')
                temp.push_back(s[i++]);
            reverse(temp.begin(),temp.end());
            ans+=temp;
            if(i!=n)
                ans+=" ";
            i++;
        }
        return ans;
    }
};