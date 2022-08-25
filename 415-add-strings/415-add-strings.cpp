class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        bool carry=0;
        if((int)num1.length()<(int)num2.length())
        {
            swap(num1,num2);
        }
        for(int i=0;i<(int)num1.length();i++)
        {
            int temp=num1[i]-'0'+carry;
            if(i<(int)num2.length())
            {
                temp+=(num2[i]-'0');
            }    
            carry=temp/10;
            num1[i]='0'+temp%10;
        }
        if(carry==1)
        {
            num1.push_back('1');
        }
        reverse(num1.begin(),num1.end());
        return num1;
    }
};