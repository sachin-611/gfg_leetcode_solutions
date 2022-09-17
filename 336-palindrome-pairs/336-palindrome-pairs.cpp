class Solution {
public:
    bool check(string s1)
    {
        int i=0;int j=s1.size()-1;
        while(i<j)
        {
            if(s1[i]!=s1[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        int n=words.size();
        unordered_map<string, int> m;
        for(int i=0;i<n;++i){
            
            auto s= words[i];
            reverse(s.begin(),s.end());
            m[s]=i;
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<=words[i].size(); ++j){
                string st1 = words[i].substr(0,j); // prefix
                string st2 = words[i].substr(j);    //sufix           
                 
                 if(m.count(st1) && check(st2) && m[st1] != i) {
                     ans.push_back({i, m[st1]});    
                 }

                 if(!st1.empty() && m.count(st2) && check(st1) && m[st2] != i) {
                     ans.push_back({m[st2], i});
                 }
            }            
        }
        return ans;
        map<string,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            string temp=words[i];
            reverse(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            int m=words[i].size();
            for(int j=0;j<=m;j++)
            {
                string s1=words[i].substr(0,j);
                string s2=words[i].substr(j);
                if(check(s1) and mp.count(s2))
                {
                    for(auto kms:mp[s2])
                        if(i!=kms)
                            ans.push_back({kms,i});
                }
                if(s1.empty()==false and check(s2) and mp.count(s1))
                {
                    for(auto kms:mp[s1])
                        if(i!=kms)
                            ans.push_back({kms,i});
                }
            }
        }
        return ans;
    }
};