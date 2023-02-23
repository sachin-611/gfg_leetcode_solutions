class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> cp;
        for(int i=0;i<profits.size();i++){
            cp.push_back({capital[i],profits[i]});
        }
        sort(cp.begin(),cp.end());
        priority_queue<int> pq;
        int x=0;
        int n = profits.size();
        for(int j=0;j<k;j++){
            while(x<n && cp[x].first<=w){
                pq.push(cp[x].second);
                x++;
            }

            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
        }

        return w;

    }
};