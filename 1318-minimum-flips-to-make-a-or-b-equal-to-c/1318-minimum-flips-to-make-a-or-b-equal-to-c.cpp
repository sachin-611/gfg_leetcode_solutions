class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<31;i++){
            if((c&(1<<i))!=0){
                if((a&(1<<i))==0 and (b&(1<<i))==0)
                    cnt++;
            }else{
                if((a&(1<<i))!=0)
                    cnt++;
                if((b&(1<<i))!=0)
                    cnt++;
            }
        }
        return cnt;
    }
};