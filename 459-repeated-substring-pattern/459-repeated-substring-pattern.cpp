class Solution {
public:
    bool repeatedSubstringPattern(string s) {
            string temp="";
            for(int i=0;i<=s.length()/2;i++)
            {
                temp.push_back(s[i]);
                string tem=temp;
                int cnt=0;
                while(tem.length()<s.length())
                {
                    tem+=temp;
                    cnt++;
                }
                if(tem==s and cnt)
                    return true;
            }
        return false;
    }
};