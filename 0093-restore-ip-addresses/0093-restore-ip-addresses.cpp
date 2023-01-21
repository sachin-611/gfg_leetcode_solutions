class Solution {
public:
    vector<string>res;
    bool check(string &s)
    {
        int i=0;
        int n=s.length();
        while(i<n)
        {
            int cnt=0;
            string temp="";
            while(i<n and s[i]!='.' and cnt<=255 and cnt>=0)
            {
                cnt=cnt*10+(s[i]-'0');
                temp.push_back(s[i]);
                i++;       
            }
            i++;
            if(!(cnt>=0 and cnt<=255) || temp=="")
                return false;
            if(temp[0]=='0' and temp.size()>1)
                return false;
        }
        return true;
    }
    void cal(int i,string &s,string temp,int cnt,int n)
    {
        if(i==n || cnt==0)
        {
            if(cnt!=0)
                return;
            while(i<n)
            {
                temp.push_back(s[i]);
                i++;
            }
            if(check(temp))
            {
                res.push_back(temp);
            }
            return;
        }
        temp.push_back('.');
        cal(i,s,temp,cnt-1,n);
        temp.pop_back();
        temp.push_back(s[i]);
        cal(i+1,s,temp,cnt,n);
        temp.pop_back();
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        cal(0,s,"",3,s.size());
        return res;
    }
};