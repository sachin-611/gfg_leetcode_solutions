// class datas{
//     public:
//     int ind;
//     int eff;
//     int ltr;
//     int rtl;
//     int pt;
//     int dt;
//     int avail;
//     int id;
    
// };
// class cmp{
//     public :
//     bool operator()(datas &d1,datas &d2)
//     {
//         if(d1.eff==d2.eff)
//             return d1.ind<d2.ind;
//         return d1.eff<d2.eff;
//     }
// };
// class cmp2{
//     public:
//     bool operator()(datas &d1,datas &d2)
//     {
//         return d1.avail>d2.avail;
//     }
// };
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int, int>> bq_l, bq_r;
    set<pair<int, int>> wh_l, wh_r;
    int bridge_t = 0;
    for (int i = 0; i < k; ++i)
        bq_l.push({time[i][0] + time[i][2], i});
    while (n || bq_r.size() + wh_r.size()) {
      while (!wh_l.empty() && begin(wh_l)->first <= bridge_t) {
          int i = begin(wh_l)->second;
          bq_l.push({time[i][0] + time[i][2], i});
          wh_l.erase(begin(wh_l));
      }
      while (!wh_r.empty() && begin(wh_r)->first <= bridge_t) {
          int i = begin(wh_r)->second;
          bq_r.push({time[i][0] + time[i][2], i});
          wh_r.erase(begin(wh_r));
      }
      if (!bq_r.empty()) {
          int i = bq_r.top().second; bq_r.pop();
          bridge_t += time[i][2];
          wh_l.insert({bridge_t + time[i][3], i});
      }
      else if (!bq_l.empty() && n) {     
          int i = bq_l.top().second; bq_l.pop();
          --n;
          bridge_t += time[i][0];
          wh_r.insert({bridge_t + time[i][1], i});        
      }
      else
          bridge_t = min(!wh_l.empty() && n ? begin(wh_l)->first : INT_MAX,
                         !wh_r.empty() ? begin(wh_r)->first : INT_MAX);
    }
    return bridge_t;
    //     priority_queue<datas,vector<datas>,cmp>left,right;
    //     priority_queue<datas,vector<datas>,cmp2>pick,drop;
    //     datas temp;
    //     for(int i=0;i<k;i++){
    //         left.push({i,(time[i][0]+time[i][2]),time[i][0],time[i][2],time[i][1],time[i][3],0});
    //     }
    //     int ctime=0;
    //     vector<int>times;
    //     while(n)
    //     {
    //         while(drop.empty()==false and ctime>=drop.top().avail){
    //             temp=drop.top();drop.pop();
    //             left.push(temp);
    //         }
    //         while(pick.empty()==false and ctime>=pick.top().avail){
    //             temp=pick.top();
    //             pick.pop();
    //             right.push(temp);
    //         }
    //         if(right.empty()==false){
    //             temp=right.top();right.pop();
    //             n--;                                
    //             ctime+=temp.rtl;
    //             times.push_back(ctime);
    //             temp.avail=ctime+temp.dt;
    //             drop.push(temp);
    //             if(n==0)
    //                 return ctime;
    //             continue;
    //         }
    //         if(left.empty()==false and n>right.size()+pick.size()){
    //             temp=left.top();
    //             left.pop();
    //             ctime+=temp.ltr;
    //             temp.avail=ctime+temp.pt;
    //             pick.push(temp);
    //             continue;
    //         }
    //         int leftfinishtime=(drop.empty()==false?drop.top().avail:1e9);
    //         int rightfinishtime=(pick.empty()==false?pick.top().avail:1e9);
    //         if(leftfinishtime<rightfinishtime){
    //             temp=drop.top();
    //             drop.pop();
    //             left.push(temp);
    //             ctime=temp.avail;
    //         }else{
    //             temp=pick.top();
    //             pick.pop();
    //             right.push(temp);
    //             ctime=temp.avail;
    //         }
    //     }
    //     return times.back();
    //     return 0;
    }
    
};