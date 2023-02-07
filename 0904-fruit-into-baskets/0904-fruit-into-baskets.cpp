class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>m;
        int i=0,j=0,n=fruits.size();
        int ans=0;
        while(j<n){
            while(j<n and (m.count(fruits[j])==1 or (m.size()<2))){
                m[fruits[j]]++;
                j++;
            }
            ans=max(j-i,ans);
            while(i<n and m.size()==2){
                if(m[fruits[i]]==1){
                    m.erase(fruits[i]);
                }
                else{
                    m[fruits[i]]--;
                }
                i++;
            }
        }
        return ans;
    }
};