class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int,int>>q;
        pair<int,int>p;
        q.push({0,1});
        int level=0,sz;
        unordered_set<int>cnts(forbidden.begin(),forbidden.end());
        set<pair<int,int>>vis;
        vis.insert({0,1});
        while(q.empty()==false){
            sz=q.size();
            while(sz--){
                p=q.front();
                q.pop();
                if(p.first==x)
                    return level;
                if(p.second==1 and p.first-b>=0 and cnts.count(p.first-b)==0 and vis.count({p.first-b,0})==0){
                    q.push({p.first-b,0});
                    vis.insert({p.first-b,0});
                }
                if(p.first+a<x+6000 and cnts.count(p.first+a)==0 and vis.count({p.first+a,1})==0){
                    q.push({p.first+a,1});
                    vis.insert({p.first+a,1});
                }
            }
            level++;
        }
        return -1;
    }
};