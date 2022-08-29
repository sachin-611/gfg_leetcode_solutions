/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=0;
        while(l<=n)
        {
            int mid=(n-l)/2+l;
            int val=guess(mid);
            if(val==-1)
            {
                n=mid-1;
            }
            else if(val==1)
            {
               l=mid+1; 
            }
            else
            {
                return mid;
            }
        }
        return 0;
    }
};