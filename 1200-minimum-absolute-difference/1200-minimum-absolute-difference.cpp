        vector<vector<int>>a;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minis=arr[1]-arr[0];
        a.clear();
        for(int i=1;i<arr.size();i++)
        {minis=min(minis,arr[i]-arr[i-1]);}
        for(int i=1;i<arr.size();i++)
        {if(minis==arr[i]-arr[i-1])
        {a.push_back({arr[i-1],arr[i]});}}
        return a;
    }
};