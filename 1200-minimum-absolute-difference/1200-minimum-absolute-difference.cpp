class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minis=1000000000;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++)
            minis=min(minis,arr[i]-arr[i-1]);
        vector<vector<int>>a;
        for(int i=1;i<arr.size();i++)
            if(minis==arr[i]-arr[i-1])
                a.push_back({arr[i-1],arr[i]});
        return a;
    }
};