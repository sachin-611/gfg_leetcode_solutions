class datas{
    public:
    int ind;
    int eff;
    int ltr;
    int rtl;
    int pt;
    int dt;
    int avail;
    int id;
    
};
class cmp{
    public :
    bool operator()(datas &d1,datas &d2)
    {
        if(d1.eff==d2.eff)
            return d1.ind<d2.ind;
        return d1.eff<d2.eff;
    }
};
class cmp2{
    public:
    bool operator()(datas &d1,datas &d2)
    {
        return d1.avail>d2.avail;
    }
};
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<datas,vector<datas>,cmp>left,right;
        priority_queue<datas,vector<datas>,cmp2>pick,drop;
        datas temp;
        for(int i=0;i<k;i++){
            left.push({i,(time[i][0]+time[i][2]),time[i][0],time[i][2],time[i][1],time[i][3],0});
        }
        int ctime=0;
        vector<int>times;
        while(n)
        {
            while(drop.empty()==false and ctime>=drop.top().avail){
                temp=drop.top();drop.pop();
                left.push(temp);
            }
            while(pick.empty()==false and ctime>=pick.top().avail){
                temp=pick.top();
                pick.pop();
                right.push(temp);
            }
            if(right.empty()==false){
                temp=right.top();right.pop();
                n--;                                
                ctime+=temp.rtl;
                times.push_back(ctime);
                temp.avail=ctime+temp.dt;
                drop.push(temp);
                if(n==0)
                    return ctime;
                continue;
            }
            if(left.empty()==false and n>right.size()+pick.size()){
                temp=left.top();
                left.pop();
                ctime+=temp.ltr;
                temp.avail=ctime+temp.pt;
                pick.push(temp);
                continue;
            }
            int leftfinishtime=(drop.empty()==false?drop.top().avail:1e9);
            int rightfinishtime=(pick.empty()==false?pick.top().avail:1e9);
            if(leftfinishtime<rightfinishtime){
                temp=drop.top();
                drop.pop();
                left.push(temp);
                ctime=temp.avail;
            }else{
                temp=pick.top();
                pick.pop();
                right.push(temp);
                ctime=temp.avail;
            }
        }
        return times.back();
    //     return 0;
    }
    
};