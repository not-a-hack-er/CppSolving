class MyCircularQueue {
public:
    vector<int> v;
    int front,rear,cnt,k;
    MyCircularQueue(int k) {
        v.resize(k);
        front=0;
        rear=0;
        cnt=0;
        this->k=k;
    }
    
    bool enQueue(int value) {
        if(cnt==k)
            return false;
        v[rear]=value;
        rear=(rear+1)%k;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt==0)
            return false;
        front=(front+1)%k;
        cnt--;
        return true;
    }
    
    int Front() {
        if(cnt==0)
            return -1;
        return v[front];
    }
    
    int Rear() {
        if(cnt==0)
            return -1;
        return v[(rear-1+k)%k];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==k;
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