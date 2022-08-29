class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        for(int i=0;i<=(int)haystack.length()-(int)needle.length();i++)
        {
            bool ok=1;
            for(int j=0;j<needle.length();j++)
            {
                if(i+j>=haystack.length() ||haystack[i+j]!=needle[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                return i;
        }
        return -1;
    }
};