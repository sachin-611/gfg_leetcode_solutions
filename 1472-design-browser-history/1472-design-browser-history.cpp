struct node{
  node *next,*prev;
    string data;
};
class BrowserHistory {
public:
    node* cur;
    BrowserHistory(string homepage) {
        cur= new node;
        cur->data=homepage;
        cur->next=cur->prev=nullptr;
    }
    void deletes(node* point){
        while(point){
            auto temp=point->next;
            delete(point);
            // i/f(temp){
                point=temp;
            // }
        }
    }
    void visit(string url) {
        delete(cur->next);
        cur->next=new node();
        cur->next->prev=cur;
        cur=cur->next;
        cur->next=nullptr;
        cur->data=url;
    }
    
    string back(int steps) {
        while(steps){
            steps--;
            if(cur->prev){
                cur=cur->prev;
            }
        }
        return cur->data;
    }
    
    string forward(int steps) {
        while(steps){
            steps--;
            if(cur->next){
                cur=cur->next;
            }
        }
        return cur->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */