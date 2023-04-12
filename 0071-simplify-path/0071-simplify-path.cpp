class Solution {
public:
    string simplifyPath(string path) {
        int i=1;
        int n=path.length();
        vector<string>res;
        while(i<n){
            string temp="";
            while(i<n and path[i]=='/')i++;
            while(i<n and path[i]!='/'){
                temp.push_back(path[i++]);
            }
            if(temp=="."){
                continue;
            }
            if(temp==".."){
                if(!res.empty()){
                    res.pop_back();
                }
                continue;
            }
            if(temp!="")
            res.push_back(temp);
        }
        string temp="";
        for(string i:res){
            temp+='/';
            temp+=i;
        }
        if(temp=="")temp="/";
        return temp;
    }
};