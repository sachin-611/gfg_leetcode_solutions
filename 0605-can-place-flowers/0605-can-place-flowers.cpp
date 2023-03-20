class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        for(int i=0;i<m and n;i++){
            if(i-1>=0 and flowerbed[i-1]==1){
                continue;
            }
            if(i+1<m and flowerbed[i+1]==1){
                continue;
            }
            if(flowerbed[i]==0){
                flowerbed[i]=1;
                n--;
            }
        }
        return n==0;
    }
};