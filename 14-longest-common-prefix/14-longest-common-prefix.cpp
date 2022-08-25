class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        for(int i=0;i<strs[0].length();i++)
        {
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j].length()<=i || strs[j][i]!=strs[0][i])
                    return res;
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};