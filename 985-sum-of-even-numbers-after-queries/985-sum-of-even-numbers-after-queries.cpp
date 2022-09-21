class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& q) {
        vector<int>ans;
        int total=0;
        for(auto i:a)
            if(i%2==0)
                total+=i;
        for(int i=0;i<q.size();i++)
        {
            if((a[q[i][1]]+q[i][0])%2==0)
            {
                if(a[q[i][1]]%2==0)
                    total+=q[i][0];
                else
                    total+=a[q[i][1]]+q[i][0];
            }
            else
            {
                if(a[q[i][1]]%2==0)
                    total-=a[q[i][1]];
            }
            a[q[i][1]]+=q[i][0];
            ans.push_back(total);
        }
        return ans;
    }
};