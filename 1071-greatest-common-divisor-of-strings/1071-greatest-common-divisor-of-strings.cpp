class Solution {
    bool check(string t,string tar){
        string s=t;
        while(s.length()<tar.length())s+=t;
        return s==tar;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string temp="";
        string res="";
        for(int i=0;i<str1.size();i++){
            temp.push_back(str1[i]);
            if(check(temp,str1)and check(temp,str2))
                res=temp;
        }
        return res;
    }
};