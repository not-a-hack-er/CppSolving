
//User function Template for C++

class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        sort(array.begin(),array.end()) ;
        long result=1;
        for(int i=0;i<n;i++)
        {
            if(array[i]>result)
            {
                return result;
            }
            result+= array[i];
        }
        return result;
    } 
};


