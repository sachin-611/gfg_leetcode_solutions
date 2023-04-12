class Solution {
public:
    int minimizeMax(vector<int>& num, int p) {
        sort(num.begin(),num.end());
       int res,n=num.size(),i,l=0,h=num[num.size()-1]-num[0],cnt,mid;
        while(l<=h){
            mid=((h-l)>>1) + l;
            cnt=0;
            for(i=1;i<n;++i){
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