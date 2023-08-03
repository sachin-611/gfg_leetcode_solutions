class Solution {
public:
    map<char,string>m;
    vector<string>ans;
    void solve(string &s,int i,string t){
        if(i==s.size()) {
            ans.push_back(t);
            return;
        }
        for(auto ch:m[s[i]]){
            solve(s,i+1,t+ch);
        }
    }
    vector<string> letterCombinations(string digit) {
        if(digit.empty())
            return {};
        m.clear();
        ans.clear();
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        solve(digit,0,"");
        return ans;
    }
};