class Solution {
public:
    string convert(string &s, int numRows) {
        if(numRows==1)
            return s;
        vector<string>ok(numRows);
        int i=0;
        int next=0;
        int n=s.length();
        bool forw=1;
        while(i<n){
            ok[next].push_back(s[i]);
            i++;
            if(forw){
                if(next==numRows-1){
                    next--;
                    forw=!forw;
                }else{
                    next++;
                }
            }else{
                if(next==0){
                    next=1;
                    forw=1;
                }else{
                    next--;
                }
            }
        }
        string res="";
        for(auto &i:ok){
            res=res+i;
        }
        return res;
    }
};