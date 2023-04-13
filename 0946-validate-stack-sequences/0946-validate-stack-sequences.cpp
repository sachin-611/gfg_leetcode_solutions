class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int>s;
        set<int>used;
        int i=0,j=0,n=pu.size();
        while(j<n){
            while(!used.count(po[j])){
                s.push(pu[i]);
                used.insert(pu[i]);
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