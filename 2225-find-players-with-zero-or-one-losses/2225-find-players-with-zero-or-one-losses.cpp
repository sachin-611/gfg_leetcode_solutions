class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int>a;
        unordered_map<int,int>w,l;
        for(auto &i:matches){
            w[i[0]]++;
            l[i[1]]++;
            a.insert(i[0]);
            a.insert(i[1]);
        }
        vector<vector<int>>res(2);
        for(auto &i:a){
            if(l.count(i)==0){
                res[0].push_back(i);
            }else if(l[i]==1){
                res[1].push_back(i);
            }
        }
        return res;
    }
};