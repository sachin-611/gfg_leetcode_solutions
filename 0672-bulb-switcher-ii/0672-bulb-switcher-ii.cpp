class Solution {
public:
    set<int>ok;
        int bit;
    int ans;
    int type1(int n){
        for(int i=1;i<=bit;i++){
            n=n^((1<<(i-1)));
        }
        return n;
    }
    int type2(int n){
        for(int i=1;i<=bit;i++){
            if(i%2==0)
            n=n^((1<<(i-1)));
        }
        return n;
    }
    int type3(int n){
        for(int i=1;i<=bit;i++){
            if(i%2==1)
            n=n^((1<<(i-1)));
        }
        return n;
    }
    int type4(int n){
        for(int i=1;i<=bit;i++){
            if(i%3==1)
            n=n^((1<<(i-1)));
        }
        return n;
    }
    void solve(int n,int presses){
        if(presses==0){
            ok.insert(n);
            ans=max(ans,(int)ok.size());
            return;
        }
        solve(type1(n),presses-1);
        
        solve(type2(n),presses-1);
        
        solve(type3(n),presses-1);
        
        solve(type4(n),presses-1);
    }
    void print(int o){
        if(o==0){
            cout<<"0";
        }
        while(o){
            cout<<(o&1)<<" ";
            o/=2;
        }
        cout<<endl;
    }
    int flipLights(int n, int presses) {
        int num=0;
        bit=min(n,10);
        presses=min(4,presses);
        for(int i=1;i<=bit;i++){
            num=num|(1<<(i-1));
        }
        ans=0;
        solve(num,presses);
        return ans;
    }
};