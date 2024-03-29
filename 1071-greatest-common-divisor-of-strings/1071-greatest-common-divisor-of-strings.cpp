class Solution {
    bool check(string &t,string &tar){
        string s=t;
        while(s.length()<tar.length())s+=t;
        return s==tar;
    }
public:
    string gcdOfStrings(string &str1, string &str2) {
        if(str1.length()>str2.length())
            swap(str1,str2);
        string temp=str1;
        for(int i=0;i<str1.size();i++){
            if(check(temp,str1)and check(temp,str2))
                return temp;
            temp.pop_back();
        }
        return "";
    }
};