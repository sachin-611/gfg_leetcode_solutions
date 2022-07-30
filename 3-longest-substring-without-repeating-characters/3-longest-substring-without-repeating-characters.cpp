class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        unordered_map<char,int>mp;
        int start=0;
        queue<char>q;
        int end=0;
        int n=s.length();
        while(end<n)
        {
            if(mp[s[end]]>0)
            {
                while(start<end and mp[s[end]]>0)
                {
                    q.pop();
                    mp[s[start]]--;
                    start++;
                }
            }
            mp[s[end]]++;
            q.push(s[end]);
            ans=max(ans,(int)q.size());
            end++;
        }
        return ans;
    }
};