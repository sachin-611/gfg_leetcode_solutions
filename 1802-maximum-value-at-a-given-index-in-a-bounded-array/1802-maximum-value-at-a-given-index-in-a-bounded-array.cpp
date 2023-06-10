class Solution {
public:
    bool isPossible(long long val,int n,long long total,int ind){
        {//front
            total-=((val*(val+1))/2);
            if(ind+1<val){
                //     1 2
                // 0 1 2 3  
                long long excess=val-(ind+1);
                total+=((excess*(excess+1))/2);
            }else if(ind+1>val){
                int rem=ind+1-val;
                total-=rem;
            }
            // cout<<total<<" ";
        }
        {//back
            // 9 8 7 6 5
            // 4 5 6 7 8
            long long ele=n-(ind+1);
            val--;
            // cout<<"ele:{"<<ele<<"} ";
            total-=(val*(val+1))/2;
            if(ele<val){
                long long excess=val-ele;
                total+=(excess*(excess+1))/2;
            }else if(ele>val){
                total-=(ele-val);
            }
        }
        // cout<<total<<"\n";
        return total>=0;
    }
    int maxValue(int n, int index, int maxSum) {
        int low=1,high=maxSum;
        int res=1;
        while(low<=high){
            int mid=(high-low)/2+low;
            // cout<<mid<<" ";
            if(isPossible(mid,n,maxSum,index)){
                res=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        // cout<<endl;
        return res;
    }
};