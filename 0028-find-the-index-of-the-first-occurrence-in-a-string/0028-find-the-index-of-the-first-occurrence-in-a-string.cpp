class Solution {
public:
    int strStr(string haystack, string needle) {
        int score=0;
        for(auto i:needle){
            score+=i;
        }
        int cur=0;
        int n=haystack.length();
        int left=0,right=0;
        while(right<n){
            cur+=haystack[right];
            right++;
            if(cur>score){
                while(cur>score){
                    cur-=haystack[left];
                    left++;
                }
            }
            if(cur==score and right-left==needle.length()){
                int ok=1;
                for(int i=0;i<needle.length();i++){
                    if(left+i<n and haystack[left+i]==needle[i]){
                    }else{
                        ok=false;
                        break; 
                    }
                }
                if(ok)
                    return left;
            }
        }
        return -1;
    }
};