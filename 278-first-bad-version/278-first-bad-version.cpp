// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans=-1;
        int l=0;
        while(l<=n)
        {
            int mid=(n-l)/2+l;
            if(isBadVersion(mid))
            {
                ans=mid;
                n=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};