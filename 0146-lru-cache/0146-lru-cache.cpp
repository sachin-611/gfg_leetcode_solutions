class node{
    public:
    int data,key;
    node *next,*prev;
    node(int data,int key, node *prev=nullptr, node *next=nullptr){
        this->data=data;
        this->key=key;
        this->next=next;
        this->prev=prev;
    }
};
class LRUCache {
    node *head,*tail;
    int cnt,limit;
    unordered_map<int,node*>m;
public:
    void insert_prev(node* cur,node* target){
        auto target_prev=target->prev;
        target_prev->next=cur;
        cur->next=target;
        target->prev=cur;
        cur->prev=target_prev;
    }
    void remove(node *cur){
        auto tprev=cur->prev;
        auto tnext=cur->next;
        tprev->next=tnext;
        tnext->prev=tprev;
    }
    LRUCache(int capacity) {
        limit=capacity;
        cnt=0;
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        m.clear();
    }
    void print(node * head){
        auto temp=head;
        while(temp){
            cout<<"{"<<temp->key<<":"<<temp->data<<"}, ";
                temp=temp->next;
        ;}
        cout<<endl;
        temp=tail;
        while(temp){
            cout<<"{"<<temp->key<<":"<<temp->data<<"}, ";
            // cout<<temp->key<<" ";
                temp=temp->prev;
        ;}
        cout<<endl<<endl;;
    }
    int get(int key) {
        if(m.count(key)){
            // cout<<"In get"<<endl;
            // print(head);
            auto temp=m[key];
            remove(temp);
            insert_prev(temp,tail);
            // print(head);
            return temp->data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // cout<<"In put"<<endl;
        // print(head);
        if(m.count(key)){
            auto ok=m[key];
            ok->data=value;
            remove(ok);
            insert_prev(ok,tail);
            return;
        }
        if(cnt==limit) {
            auto cur=head->next;
            remove(cur);
            insert_prev(cur,tail);
            m.erase(cur->key);
            cur->key=key;
            cur->data=value;
            m[key]=cur;
        }
        else {
            auto temp=new node(value,key);
            insert_prev(temp,tail);
            m[key]=temp;
            cnt++;
        }
        // print(head);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */