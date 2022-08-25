class Solution {
public:
    bool isPathCrossing(string path) {
        int i=0,j=0;
        map<pair<int,int>,int>mp;
        mp[{i,j}]++;
        for(auto p:path)
        {
            if(p=='N')
                j++;
            else if(p=='S')
                j--;
            else if(p=='E')
                i--;
            else
                i++;
            mp[{i,j}]++;
            if(mp[{i,j}]>1)
                return 1;
        }
        return false;
    }
};