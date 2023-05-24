class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        int n=nums1.size();
        vector<pair<int,int>>a(n);
        for(int i=0;i<n;i++)
        {
            a[i].second=nums1[i];
            a[i].first=nums2[i];
        }
        sort(a.begin(),a.end());
        // {for(auto i:a)
        // {
        //     cout<<i.first<<" ";
        // }
        // cout<<endl;
        // for(auto i:a)
        // {
        //     cout<<i.second<<" ";
        // }
        // cout<<endl;}
        long long tot=0;
        multiset<int>m;
        for(int i=0;i<k;i++)
        {
            m.insert(a[n-1-i].second);
            tot+=a[n-1-i].second;
        }
        ans=tot*(long long)a[n-k].first;
        for(int j=k;j<n;j++)
        {
            int i=n-1-j;
            bool ad=0;
            // cout<<tot<<endl;
            if((*m.begin())<a[i].second)
            {
                ad=1;
                m.insert(a[i].second);
                tot-=(*m.begin());
                tot+=a[i].second;
                m.erase(m.begin());
                
            }
            
            long long mxs=tot;
            // cout<<mxs<<endl;
            if(ad!=1)
            {
                mxs=tot-(*m.begin())+a[i].second;
            }
            ans=max(ans,(long long)a[i].first*mxs);
            // cout<<i<<"=i "<<mxs<<" "<<a[i].first<<endl;
        }
        return ans;
    }
};