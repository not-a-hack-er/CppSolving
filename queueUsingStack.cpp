class Queue {
    // Define the data members(if any) here.
    int *arr;
    int qfront;
    int rear;
    int size;
    public:
    Queue() {
        // Implement the Constructor
        size=100001;
        arr= new int[size];
        qfront=0;
        rear=0; // Initialize your data structure here.
    }

    void enQueue(int val) {
         if(rear==size)
        {
            cout<< "queue is full"<<endl;
        }
        else
        {
            arr[rear]=val;
            rear++;
        }
    }

    int deQueue() 
    {
        if(qfront==rear)
        {
            return -1;
        }
        else
        {
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if (qfront == rear) {
              qfront = 0;
              rear = 0;
            }
            return ans;
        }
    }

    int peek()
    {
        if(qfront==rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }

    bool isEmpty() {
        if(qfront==rear)
        {
            return true;
        }
        else{
            return false;
        }
    }
};
