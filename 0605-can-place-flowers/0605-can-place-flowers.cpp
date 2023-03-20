class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        for(int i=0;i<m and n;i++){
            bool prev=1,next=1;
            if(i-1>=0 and flowerbed[i-1]==1){
                prev=0;
            }
            if(i+1<m and flowerbed[i+1]==1){
                next=0;
            }
            if(prev and next and flowerbed[i]==0){
                flowerbed[i]=1;
                n--;
            }
        }
        return n==0;
    }
};