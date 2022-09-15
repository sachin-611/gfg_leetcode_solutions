class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>m;
        for(int i:changed)
            m[i]++;
        sort(changed.begin(),changed.end());
        vector<int>res;
        for(auto i:changed)
        {
            if((m[i]>0 and m[i*2]>0 and i!=0) or (i==0 and m[i]>1))
            {
                m[i]--;
                m[i*2]--;
                res.push_back(i);
            }
        }
        if(res.size()*2==changed.size())
            return res;
        // for(int i:res)cout<<i<<" ";
        // cout<<endl;
        return {};
    }
};