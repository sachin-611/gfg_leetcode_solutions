class Solution {
public:
    string addBinary(string &a, string &b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        bool carry=0;
        if(a.length()<b.length())
            swap(a,b);
        for(int i=0;i<(int)a.length();i++)
        {
            if(i>=(int)b.length())
            {
                if(a[i]-'0'+carry==2)
                {
                    a[i]='0';
                    carry=1;
                }
                else if(a[i]-'0'+carry==1)
                {
                    a[i]='1';
                    carry=0;
                }
                else
                {
                    a[i]='0';
                    carry=0;
                }
            }
            else
            {
                int t1=a[i]-'0'+b[i]-'0'+carry;
                if(t1==3)
                {
                    a[i]='1';
                    carry=1;
                    // cout<<3<<endl;
                }
                else if(t1==2)
                {
                    a[i]='0';
                    carry=1;
                    // cout<<2<<endl;
                }
                else if(t1==1)
                {
                    a[i]='1';
                    carry=0;
                    // cout<<1<<endl;
                }
                else
                {
                    a[i]='0';
                    carry=0;
                    // cout<<0<<endl;
                }
            }
            // cout<<a[i]<<" "<<carry<<" after\n";
        }
        // cout<<carry<<endl;
        if(carry==1)
            a.push_back(carry+'0');
        reverse(a.begin(),a.end());
        return a;
    }
};