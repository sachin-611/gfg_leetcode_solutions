class node{
  public:
    int key,value,cnt;
    node *next,*prev;
    node(int key=0,int value=0,node* next=nullptr,node* prev=nullptr){
        this->key=key;
        this->cnt=1;
        this->value=value;
        this->next=next;
        this->prev=prev;
    }
};
class LFUCache {
    int limit,cnt;
    vector<pair<node*,node*>>a;
    map<int,node*>m;
    map<int,int>fre;
    void remove(node *cur){
        auto pre=cur->prev;
        auto nex=cur->next;
        pre->next=nex;
        nex->prev=pre;
    }
    void insert_before(node *cur,node *nex){
        auto pre=nex->prev;
        pre->next=cur;
        cur->next=nex;
        nex->prev=cur;
        cur->prev=pre;
    }
    void decrease(int cnt1){
        auto temp=fre[cnt1];
        // cout<<cnt1<<" "<<temp<<endl;
        
        if(temp==1){
            fre.erase(cnt1);
        }else{
            fre[cnt1]--;
        }
    }
    // void print(node *temp){
    //     node *ok=temp;
    //     while(ok){
    //         cout<<"{"<<ok->key<<" "<<ok->value<<" "<<ok->cnt<<"}, ";
    //         ok=ok->next;
    //     }
    //     cout<<endl;
    // }
    // void dbg(){
    //     int oks=0;
    //     for(auto i:a){
    //         if(i.first->next==i.second)
    //             continue;
    //         print(i.first);
    //         oks++;
    //     }
    //     cout<<endl<<"map:";
    //     for(auto i:fre){
    //         cout<<"{"<<i.first<<" "<<i.second<<"}, ";
    //     }
    //     cout<<endl<<endl;;
    // }
public:
    LFUCache(int capacity) {
        limit= capacity;
        cnt=0;
        a.resize(100002);
        m.clear();
        int oks=a.size();
        for(int i=1;i<oks;++i){
            a[i].first=new node;
            a[i].second=new node;
            a[i].first->next=a[i].second;
            a[i].second->prev=a[i].first;
            a[i].first->cnt=a[i].second->cnt=i;
        }
        // dbg();
    }
    int get(int key) {
        // cout<<"In Get"<<key<<endl;
        if(m.count(key)){
            //increase frequency and and return value 
            auto temp=m[key];
            
//             dbg();
            
            decrease(temp->cnt);
            remove(temp);
            temp->cnt++;
            fre[temp->cnt]++;
            insert_before(temp,a[temp->cnt].second);
            
            // dbg();
            // cout<<endl<<endl;
            
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // cout<<"In Put"<<key<<endl;
        // dbg();
        if(limit==0)
            return;
        if(m.count(key)){
            //update count and value
            // cout<<"update"<<endl;
            auto temp=m[key];
            // cout<<temp->cnt<<" "<<temp->key<<" "<<temp->value<<endl;
            decrease(temp->cnt);
            // dbg();
            temp->cnt++;
            temp->value=value;
            fre[temp->cnt]++;
            remove(temp);
            insert_before(temp,a[temp->cnt].second);
            
        //     dbg();
        // cout<<endl<<endl;;
       
            return;
        }
        if(cnt!=limit){
            //create new node and insert;
            // cout<<"create new node"<<endl;
            auto temp=new node(key,value);
            fre[temp->cnt]++;
            insert_before(temp,a[temp->cnt].second);
            m[key]=temp;
            cnt++;
            
        //     dbg();
        // cout<<endl;
            
            return;
        }
        //delete list frequent node and add current node
        // cout<<"overight"<<endl;
        auto least=fre.begin()->first;
        // cout<<least<<endl;
        decrease(least);
        auto oks=a[least].first->next;
        m.erase(oks->key);
        remove(oks);
        oks->cnt=1;
        oks->key=key;
        oks->value=value;
        m[key]=oks;
        fre[1]++;
        insert_before(oks,a[1].second);
        
        // dbg();
        // cout<<endl;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */