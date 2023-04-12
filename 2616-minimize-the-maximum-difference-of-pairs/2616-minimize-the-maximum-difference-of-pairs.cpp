class Solution {
public:
    int minimizeMax(vector<int>& num, int p) {
       int res,n=num.size();
        sort(num.begin(),num.end());
        long long l=0,h=num[n-1]-num[0];
        while(l<=h){
            long long mid=(l+h)>>1;
            int cnt=0;
            for(int i=1;i<n;i++){
                if(num[i]-num[i-1]<=mid)
                    cnt++,i++;
            }
            if(cnt>=p){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};