class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int>s;
        int used[1001];
        memset(used,0,sizeof(used));
        int i=0,j=0,n=pu.size();
        while(j<n){
            while(!used[po[j]]){
                s.push(pu[i]);
                used[pu[i]]=1;
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