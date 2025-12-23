class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minheap;

    for (int x : nums) {

       
        bool duplicate = false;
        priority_queue<int, vector<int>, greater<int>> temp = minheap;

        while (!temp.empty()) 
        {

            if (temp.top() == x)
            {
                duplicate = true;
                break;
            }
            temp.pop();
        }

        if (duplicate) continue;

        minheap.push(x);

        if (minheap.size() > 3)
            minheap.pop();
    }

   
    if (minheap.size() < 3) {
        while (minheap.size() > 1)
            minheap.pop();
    }

    return minheap.top();
    }
};