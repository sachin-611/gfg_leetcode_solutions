class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<string>ans;
        int n=w1.size();
        vector<vector<int>>mw1(n,vector<int>(26,0));
        vector<int>mw2(26);
        for(int i=0;i<n;i++)
        {
            for(char j:w1[i])
                mw1[i][j-'a']++;
        }
        for(string i:w2)
        {
            vector<int>mp(26);
            for(char j:i)
                mp[j-'a']++;
            for(int j=0;j<26;j++)
            {
                mw2[j]=max(mw2[j],mp[j]);
            }
        }
        for(auto i=0;i<n;i++)
        {
            bool pos=1;
            for(int j=0;j<26;j++)
            {
                if(mw2[j]<=mw1[i][j])
                {
                    pos=1;
                }
                else
                {
                    pos=0;
                    break;
                }
            }
            if(pos)
                ans.push_back(w1[i]);
        }
        return ans;
    }
};