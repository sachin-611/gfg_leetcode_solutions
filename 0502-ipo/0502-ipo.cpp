class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>a;
        int n=profits.size(),j=0;
        for(int i=0;i<n;i++){
            a.emplace_back(capital[i],profits[i]);
        }
        sort(a.begin(),a.end());
        priority_queue<int>p;
        for(int i=0;i<k;i++){
            while(j<n and a[j].first<=w){
                p.push(a[j].second);
                j++;
            }
            if(p.empty()){
                break;
            }
            w+=p.top();
            p.pop();
        }
        return w;
    }
};