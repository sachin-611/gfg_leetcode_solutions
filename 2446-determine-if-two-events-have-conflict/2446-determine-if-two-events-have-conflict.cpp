class Solution {
    bool comp(string s1,string s2){
        int hh1=(s1[0]-'0')*10+(s1[1]-'0');
        int mm1=(s1[3]-'0')*10+(s1[4]-'0');
        int hh2=(s2[0]-'0')*10+(s2[1]-'0');
        int mm2=(s2[3]-'0')*10+(s2[4]-'0');
        // cout<<hh1<<":"<<mm1<<" "<<hh2<<":"<<mm2<<endl;
        if(hh1>hh2 or (hh1==hh2 and mm1>=mm2))
            return true;
        // cout<<"false"<<endl;
        return false;
    }
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string s1=event1[0],e1=event1[1],s2=event2[0],e2=event2[1];
        return (((comp(s1,s2) and comp(e2,s1))or((comp(s2,s1) and comp(e1,s2)))));
    }
};