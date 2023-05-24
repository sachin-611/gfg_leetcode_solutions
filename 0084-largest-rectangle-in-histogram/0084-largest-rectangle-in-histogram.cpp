class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int> s;
        s.push(0);
        int n=heights.size();
        if(n==1)
            return heights[0];
        vector<int>l(n,-1),r(n,-1);
        for(int i=1;i<n;i++){
            while(s.empty()==false and heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()==0)
                l[i]=s.top();
            s.push(i);
        }
        stack<int>s1;
        s1.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(s1.empty()==false and heights[s1.top()]>=heights[i]){
                s1.pop();
            }
            if(s1.empty()==0)
                r[i]=s1.top();
            s1.push(i);
        } 
        for(int i=0;i<n;i++){
            int left=0,right=n-1;
            if(l[i]!=-1)
                left=l[i]+1;
            if(r[i]!=-1)
                right=r[i]-1;
            ans=max((right-left+1)*heights[i],ans);
            
        }
        return ans;
    }
};