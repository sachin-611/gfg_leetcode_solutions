class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>a(height);
        int n=height.size();
        int maxi=height[0];
        for(int i=0;i<n;i++)
        {
            a[i]=maxi;
            maxi=max(maxi,height[i]);        
        }
        maxi=height[n-1];
        for(int i=0;i<n;i++)
        {
            a[n-1-i]=min(maxi,a[n-1-i]);
            maxi=max(maxi,height[n-1-i]);        
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>height[i])
            ans+=(a[i]-height[i]);
        }
        return ans;
    }
};