class MyCircularQueue {
    vector<int>a;
    int top,rear,size,cap;
public:
    MyCircularQueue(int k) {
        a.resize(k);
        cap=k;
        size=0;
        top=0;
        rear=-1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        rear=(rear+1)%a.size();
        a[rear]=value;
        size+=1;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        top=(top+1)%a.size();
        size-=1;
        return true;
    }
    
    int Front() {
        if(!isEmpty())
            return a[top];
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
            return a[rear];
        return -1;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */