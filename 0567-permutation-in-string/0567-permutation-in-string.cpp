class Solution {
    map<char,int>m1,m2;
    bool check(){
        // return m1==m2;
        map<char,int>temp;
        for(auto i:m1){
            // cout<<"{"<<i.first<<" "<<i.second<<"} ";
            temp[i.first]=i.second;
        }
        // cout<<endl;
        for(auto i:m2){
            // cout<<"{"<<i.first<<" "<<i.second<<"} ";
            temp[i.first]-=i.second;
        }
        // cout<<endl;
        for(auto i:temp){
            if(i.second!=0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        m1.clear();
        m2.clear();
        int n=s1.length(),m=s2.length();
        for(int i=0;i<n;i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        int ans=check();
        if(ans)
            return true;
        for(int i=n;i<m;i++){
            if(m2[s2[i-n]]==1){
                m2.erase(s2[i-n]);
            }else{
            m2[s2[i-n]]--;
                
            }
            m2[s2[i]]++;
            ans=check();
            if(ans)
                return true;
        }
        return false;
    }
};