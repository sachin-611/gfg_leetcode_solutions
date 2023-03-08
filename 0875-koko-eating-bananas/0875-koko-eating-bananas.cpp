class Solution {
public:
    long long minEatingSpeed(vector<int>& piles, int h) {
        long long left=1,right=1e16;
        int res;  
        while(left<=right){
            long long mid=left+(right-left)/2;
            int hrs=0;
            for(int i:piles){
                hrs+=i/mid;
                i=i%mid;
                if(i)hrs++;
            }
            if(hrs<=h){
                res=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return res;
    }
};