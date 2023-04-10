class Solution {
public:
    bool isValid(string s) {
        string temp="";
        for(char i:s)
        {
            if(i=='(' || i=='[' || i=='{')
                temp.push_back(i);
            else
            {
                if(temp.empty())
                    return false;
                else if(temp.back()=='(')
                {
                    if(i!=')')
                        return false;
                    else
                        temp.pop_back();
                }
                else if(temp.back()=='[')
                {
                    if(i!=']')
                        return false;
                    else
                        temp.pop_back();
                }
                else if(temp.back()=='{')
                {
                    if(i!='}')
                        return false;
                    else
                        temp.pop_back();
                }
            }
        }
        return temp.empty();
    }
};