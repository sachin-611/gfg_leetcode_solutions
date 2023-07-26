class Solution {
public:
    bool pos(vector<int>&a,double time,int speed ){
        double times=0;
        for(int i=0;i<a.size();i++){
            if(i+1<a.size()){
                times+=((a[i]+speed-1)/speed);
            }else{
                times+=(a[i]/(double)speed);
            }
        }
        return time>=times;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1;
        int low=1,high=10000000;
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