class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>res;
            int l=0,h=potions.size();
            int n=h;
        sort(potions.begin(),potions.end());
        for(int i:spells){
            l=0,h=n-1;
            int ans=n;
            while(l<=h){
                int mid=(h-l)/2+l;
                long long pro=i*(long long)potions[mid];
                if(pro>=success){
                    ans=mid;
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }
            res.push_back(n-ans);
        }
        return res;
    }
};