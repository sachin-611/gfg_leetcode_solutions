class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        bool carry=1;
        for(auto &i:digits)
        {
            if(i+carry>9)
            {
                i=(i+carry)%10;
                carry=1;
            }
            else
            {
                i=(i+carry);
                carry=0;
            }
        }
        if(carry)
        {
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};