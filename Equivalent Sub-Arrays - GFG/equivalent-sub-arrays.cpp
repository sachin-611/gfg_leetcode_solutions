// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
  
int countDistinctSubarray(int s[], int n)
   {
       unordered_map<int,int>m;
       for(int i=0;i<n;i++)
       {
           m[s[i]]++;
       }
       int k=m.size();
       int i=0,j=0;
       int count=0;
       unordered_map<int,int>mp;
       while(j<n)
       {
           mp[s[j]]++;
           if(mp.size()<k)
           {
               j++;
           }
           else if(mp.size()==k)
           {
               count+=n-j;
               while(mp.size()==k)
               {
                   mp[s[i]]--;
                   if(mp[s[i]]==0){
                       mp.erase(s[i]);
                   }
                   i++;
                   if(mp.size()==k)
                   {
                       count+=n-j;
                   }
               }
               j++;
               
           }
       }
       return count;
   }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends