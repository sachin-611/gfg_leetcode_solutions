class Solution {
public:
    string maximumNumber(string &num, const vector<int>& change) {
        int i=0,n=num.size();
        while(i<n){
            int chan=0;
            int digi=num[i]-'0';
            while(i<n and (digi<change[digi] or (chan and digi==change[digi]))){
                chan=1;
                num[i]=change[num[i]-'0']+'0';
                i++;
                if(i<n)
                digi=num[i]-'0';
            }
            if(chan)
                break;
            i++;
        }
        return num;
    }
};