class Solution {
    bool pos(const string &num,int i,const vector<int>&change,int prev){
        int digi=num[i]-'0';
        if(digi<change[digi] or (prev and digi==change[digi]))
            return 1;
        return 0;
    }
public:
    string maximumNumber(string &num, const vector<int>& change) {
        int i=0,n=num.size();
        while(i<n){
            int chan=0;
            while(i<n and pos(num,i,change,chan)){
                chan=1;
                num[i]=change[num[i]-'0']+'0';
                i++;
            }
            if(chan)
                break;
            i++;
        }
        return num;
    }
};