        vector<vector<int>>a;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minis=1000000000;
        a.clear();
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++)
        {minis=min(minis,arr[i]-arr[i-1]);}
        for(int i=1;i<arr.size();i++)
        {if(minis==arr[i]-arr[i-1])
        {a.push_back({arr[i-1],arr[i]});}}
        return a;
    }
};