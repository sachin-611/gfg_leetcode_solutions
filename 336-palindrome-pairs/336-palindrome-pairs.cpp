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
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string temp=words[i];
            reverse(temp.begin(),temp.end());
            mp[temp]=i;
        }
        for(int i=0;i<n;i++)
        {
            int m=words[i].size();
            string s1="";
            string s2=words[i];
            for(int j=0;j<=m;j++)
            {
                if(s1.empty()==false and  mp.count(s2) and i!=mp[s2] and check(s1))
                {
                            ans.push_back({mp[s2],i});
                }
                if( mp.count(s1) and i!=mp[s1] and check(s2))
                {
                            ans.push_back({i,mp[s1]});
                }
                if(j!=m)
                {
                    s2.erase(0,1);
                    s1.push_back(words[i][j]);   
                }
            }
        }
        return ans;
    }
};