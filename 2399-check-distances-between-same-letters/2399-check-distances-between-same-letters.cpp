class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<vector<int>>a(26);
        int cnt=0;
        for(char i:s)
        {
            a[i-'a'].push_back(cnt++);
        }
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<(int)a[i].size();j++)
            {
                if(a[i][j]!=a[i][j-1]+distance[i]+1)
                    return false;
            }
        }
        return true;
    }
};