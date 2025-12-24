class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;int sec=0;
        for(int x:amount)
        pq.push(x);
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a==0||b==0)
            sec+=(a+b);
            else{
                sec++;
                a--;
                b--;
                pq.push(a);
                pq.push(b);
            }

        }
            return sec;
         
    }
};