class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>a(profits.size());
        for(int i=0;i<profits.size();i++){
            a[i].second=profits[i];
            a[i].first=capital[i];
        }
        sort(a.begin(),a.end());
        int res=w;
        priority_queue<int>p;
        int j=0;
        for(int i=0;i<k;i++){
            while(j<profits.size() and a[j].first<=w){
                p.push(a[j].second);
                j++;
            }
            if(p.empty()){
                break;
            }
            w+=p.top();
            res+=p.top();
            p.pop();
        }
        return res;
    }
};