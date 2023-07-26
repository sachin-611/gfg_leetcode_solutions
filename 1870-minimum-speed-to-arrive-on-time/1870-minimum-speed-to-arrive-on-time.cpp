class Solution {
public:
    int n;
    double pos(vector<int>&a,int speed ){
        double ok=0;
        for(int i=0;i<n;i++){
            if(i+1<n){
                ok+=((a[i]+speed-1)/speed);
            }else{
                ok+=(a[i]/(double)speed);
            }
        }
        return ok;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1;
        int low=1,high=1e9;
        n=dist.size();
        while(low<=high){
            long int mid=(high+low)/2;
            if(hour>=pos(dist,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};