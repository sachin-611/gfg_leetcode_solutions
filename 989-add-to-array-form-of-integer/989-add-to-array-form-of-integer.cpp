class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        reverse(num.begin(),num.end());
        for(int i=0;i<num.size();i++)
        {
            
            int ne=(num[i]+k%10+carry)%10;
            carry=(num[i]+k%10+carry)/10;
            num[i]=ne;
            k=k/10;
        }
        while(k>0)
        {
            int ne=(k%10+carry)%10;
            carry=(k%10+carry)/10;
            num.push_back(ne);
            k=k/10;
        }
        if(carry>0)
        {num.push_back(carry);}
        reverse(num.begin(),num.end());
        return num;
    }
};