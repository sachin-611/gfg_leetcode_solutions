class Solution {
public:
    void add(string &a,string &b)
    {
        string res=a;
        if(a.length()<b.length())
            swap(a,b);
        bool carry=0;
        for(int i=0;i<a.length();i++)
        {
            a[i]=(a[i]-'0')+carry;
            if(i<b.length())
                a[i]+=(b[i]-'0');
            carry=a[i]/10;
            a[i]%=10;
            a[i]+='0';
        }
        if(carry)
            a.push_back(carry+'0');
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
            // cout<<temp<<" \n";
            add(res,temp);
            // cout<<res<<"\n";
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