class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int res=0,l=0,h=letters.size()-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            if(letters[mid]>target){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return letters[res];
    }
};