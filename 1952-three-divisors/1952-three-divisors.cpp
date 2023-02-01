class Solution {
public:
    bool isThree(int n) {
        if(n==1)return false;
        int temp=sqrt(n);
        for(int i=2;i*i<=temp;i++){
            if(temp%i==0){
                return false;
            }
        }
        return temp*temp==n;
    }
};