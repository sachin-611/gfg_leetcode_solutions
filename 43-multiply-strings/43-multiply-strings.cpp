class Solution {
public:
    void add(string &a,string &b)
    {
        
    }
    string multiply(string num1, string num2) {
        string res="";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int cnt=0;
        for(char i:num1)
        {
            string temp="";
            for(int k=0;k<cnt;k++)
            {
                temp.push_back('0');
            }
            int carry=0;
            for(char j:num2)
            {
                int val=(i-'0')*(j-'0')+carry;
                carry=val/10;
                val%=10;
                temp.push_back(val+'0');
            }
            if(carry)
            {
                temp.push_back('0'+carry);
            }
            if(res.length()<temp.length())
            swap(res,temp);
        carry=0;
        for(int i=0;i<res.length();i++)
        {
            res[i]=(res[i]-'0')+carry;
            if(i<temp.length())
                res[i]+=(temp[i]-'0');
            carry=res[i]/10;
            res[i]%=10;
            res[i]+='0';
        }
        if(carry)
            res.push_back(carry+'0');
            cnt++;
        }
        while(!res.empty())
        {
            if(res.back()=='0')
                res.pop_back();
            else
                break;
        }
        if(res.empty())
            res.push_back('0');
        reverse(res.begin(),res.end());
        return res;
    }
};