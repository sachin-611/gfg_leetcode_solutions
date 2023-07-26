class Solution {
public:
    bool pos(vector<int>&a,double time,int speed ){
        double ok=0;
        for(int i=0;i<a.size();i++){
            if(i+1<a.size()){
                ok+=((a[i]+speed-1)/speed);
            }else{
                ok+=(a[i]/(double)speed);
            }
        }
        return time>=ok;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1;
        int low=1,high=1e9;
        while(low<=high){
            long int mid=(high+low)/2;
            if(pos(dist,hour,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};