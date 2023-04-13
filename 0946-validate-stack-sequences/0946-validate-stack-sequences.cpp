class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int>s;
        vector<int>used(1001,0);
        int i=0,j=0,n=pu.size();
        while(j<n){
            while(i<n and !used[po[j]]){
                s.push(pu[i]);
                used[pu[i]]++;
                i++;
            }
            if(s.top()!=po[j]){
                return false;
            }
            s.pop();
            j++;
        }
        return true;
    }
};