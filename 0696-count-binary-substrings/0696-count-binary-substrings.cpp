class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int ans=0;
        int i=0,n=s.length();
        while(i<n){
            char c=s[i];
            int cnt=0;
            while(i<n and s[i]==c){
                i++;
                cnt++;
            }
            ans+=min(cnt,prev);
            prev=cnt;
        }
        return ans;
    }
};