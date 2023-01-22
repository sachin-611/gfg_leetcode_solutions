class Solution {
public:
    vector<vector<string>>res;
    bool isPal(string &s){
        if(s.empty())
            return false;
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }
    void cal(string s,string temp,int i,int n,vector<string>&tem){
        if(i==n)
        {
            // cout<<temp<<endl;
            // for(auto i:tem)
            //     cout<<i<<" ";
            // cout<<endl;
            if(isPal(temp)||temp=="")
            {
                if(temp!="")
                tem.push_back(temp);
                res.push_back(tem);
                if(temp!="")
                tem.pop_back();
            }
            return;
        }
        if(isPal(temp))
        {
            tem.push_back(temp);
            string oks="";
            
            cal(s,oks+s[i],i+1,n,tem);
            tem.pop_back();
        }
        cal(s,temp+s[i],i+1,n,tem);
    }
    vector<vector<string>> partition(string s) {
        vector<string>ok;
        cal(s,"",0,s.length(),ok);
        return res;
    }
};