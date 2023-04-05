class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        int i=0;
        int n=s.size();
        while(i<n){
            ans++;
            vector<int>a(26,0);
            while(i<n and a[s[i]-'a']+1<=1){
                a[s[i]-'a']++;
                i++;
            }
        }
        return ans;
    }
};