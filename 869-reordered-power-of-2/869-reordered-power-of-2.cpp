class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string pos=to_string(n);
        sort(pos.begin(),pos.end());
        for(int i=0;i<31;i++)
        {
            if(pos.length()==to_string(1<<i).length())
            {
                string temp=to_string(1<<i);
                sort(temp.begin(),temp.end());
                if(temp==pos)
                    return true;
            }        
        }
        return false;
    }
};