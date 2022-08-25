class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        reverse(num.begin(),num.end());
        for(auto &i:num)
        {
            
            int ne=(i+k%10+carry)%10;
            carry=(i+k%10+carry)/10;
            i=ne;
            k/=10;
        }
        while(k)
        {
            int ne=(k%10+carry)%10;
            carry=(k%10+carry)/10;
            num.push_back(ne);
            k/=10;
        }
        if(carry)
            num.push_back(carry);
        reverse(num.begin(),num.end());
        return num;
    }
};