class Solution {
public:
    unordered_set<string>s;
    map<string,vector<pair<string,double>>>g;
    double solve(string start,string end){
        if(start==end)return 1;
        queue<pair<string,double>>q;
        q.push({start,1});
        unordered_map<string,int>vis;
        vis[start]=1;
        while(q.empty()==false){
            auto front=q.front();
            q.pop();
            vis[front.first]=1;
            if(front.first==end)
                return front.second;
            for(auto &child:g[front.first]){
                if(vis[child.first]==0){
                    q.push({child.first,front.second*child.second});
                    vis[child.first]=1;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        vector<double>res;
        for(int i=0;i<e.size();i++){
            g[e[i][0]].push_back({e[i][1],v[i]});
            g[e[i][1]].push_back({e[i][0],1/v[i]});
            s.insert(e[i][0]);
            s.insert(e[i][1]);
        }
        for(auto &i:q){
            if(s.count(i[0])==0 or s.count(i[1])==0){
                res.push_back(-1);
            }else{
                res.push_back(solve(i[0],i[1]));
            }
        }
        return res;
    }
};