class twoStacks {
    int *arr;
    int top1;
    int top2;
    int size;
  public:

    twoStacks() {
        size=500;
        top1=-1;
        top2=size;
        arr=new int[size];
    }
        

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(top2-top1>1)
        {
        top1++;
        arr[top1]=x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
          if(top2-top1>1)
          {
        top2--;
        arr[top2]=x;
          }
        // code here
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        if(top1>=0)
        {
        int ans=arr[top1];
        top1--;
        return ans;
        }
        else{ return -1;
        }
        // code here
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2<size)
        {
        int ans=arr[top2];
        top2++;
        return ans;
        }
        else
        {return -1;
        }
        // code here
    }
};