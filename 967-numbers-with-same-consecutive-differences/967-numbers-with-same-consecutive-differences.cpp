class Solution {
public:
    unordered_set<int>res;
    void gen(int n,int k,string s)
    {
        if(s.length()==n)
        {
            res.insert(stoi(s));
            return;
        }
                int c=s[s.length()-1]-'0';
                if(c+k<=9)
                {
                    c=c+k;
                    s.push_back(c+'0');
                    gen(n,k,s);
                    s.pop_back();
                    c-=k;
                }
                if(c-k>=0)
                {
                    c-=k;
                    s.push_back(c+'0');
                    gen(n,k,s);
                    s.pop_back();
                    c+=k;
                }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        res.clear();
        string s="1";
        for(int i=1;i<10;i++,s[0]++)
            gen(n,k,s);
        vector<int>re(res.begin(),res.end());
        return re;
    }
};