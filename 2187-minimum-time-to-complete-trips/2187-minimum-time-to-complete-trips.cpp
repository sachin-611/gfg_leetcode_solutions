class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long res=0;
        long long left=1,right=1e15;
        while(left<=right){
            long long mid=(right-left)/2+left;
            unsigned long long cnt=0;
            for(auto i:time){
                cnt+=mid/i;
            }
            if(cnt>=totalTrips){
                res=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return res;
    }
};