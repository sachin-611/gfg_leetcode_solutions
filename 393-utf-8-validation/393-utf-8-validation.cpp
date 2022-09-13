class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i=0,n=data.size();
        while(i<n)
        {
            int type=((1<<7)&data[i]);
            if(type==0)
            {//type 1
                i++;
            }
            else
            {
                type=(1<<6)&data[i];
                if(type>0)
                {

                    type=(1<<5)&data[i];
                    if(type==0)
                    {//type 2
                        if(i+1<n && nexts(data[i+1]))
                        {
                            i+=2;
                        }
                        else
                        {
                            // cout<<"here2 ";
                            return false;
                        }
                    }
                    else
                    {
                        type=(1<<4)&data[i];
                        if(type==0)
                        {//type 3
                            if(i+2<n && nexts(data[i+1]) && nexts(data[i+2]))
                            {
                                i+=3;
                            }
                            else
                            {
                                // cout<<"here3 ";
                                return false;
                            }
                        }
                        else
                        {
                            type=(1<<3)&data[i];
                            if(type==0)
                            {
                                if(i+3<n and nexts(data[i+1]) and nexts(data[i+2]) and nexts(data[i+3]))
                                    i+=4;
                                else
                                {   
                                    // cout<<"here4 ";
                                    return false;
                                }
                            }
                            else
                            {
                                // cout<<"here none ";
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    // cout<<"here1 "<<(data[i]&(1<<6))<<" ";
                    return false;
                }
            }
        }
        return true;
    }
    bool nexts(int val)
    {
        return (val&(1<<7))>0 && (val&(1<<6))==0;
    }
};