class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<int>cur(26),tar(26);
        vector<int>res;
        for(auto i:p){
            tar[i-'a']++;
        }
        int left=0,right=0;
        for(int i=0;i<n and i<m;i++){
            cur[s[right]-'a']++;
            right++;
        }
        for(int i=n;i<=m;i++){
            int flag=1;
            for(int tem=0;tem<26;tem++){
                if(cur[tem]!=tar[tem])
                    flag=0;
            }
            if(flag){
                res.push_back(left);
            }
            if(left<m)
                cur[s[left]-'a']--;
            left++;
            if(right<m)
                cur[s[right]-'a']++;
            right++;
        }
        return res;
    }
};