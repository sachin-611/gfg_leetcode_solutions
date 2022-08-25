class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26]={};
        for(char i:magazine)
            arr[i-'a']++;
        for(char i:ransomNote)
        {
            if(arr[i-'a']==0)
                return false;
            arr[i-'a']--;
        }
        return true;
    }
};