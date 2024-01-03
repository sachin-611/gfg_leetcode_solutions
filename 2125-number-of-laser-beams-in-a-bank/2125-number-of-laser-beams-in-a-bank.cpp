class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last=0,cur=0,res=0;
        for(string s:bank){
            cur=0;
            for(char c:s){
                if(c=='1'){
                    cur++;
                }
            }
            if(cur>0){
                res+=(cur*last);
                last=cur;
            }
        }
        return res;
    }
};