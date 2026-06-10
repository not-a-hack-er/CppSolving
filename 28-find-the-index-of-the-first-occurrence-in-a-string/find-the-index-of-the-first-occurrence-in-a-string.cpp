class Solution {
public:
    int strStr(string h, string n) {
        int s= n.size();
        int k = h.size();
        
        
        for(int i=0;i<=k-s;i++)
        {
            bool check=true;
                for(int j=0;j<s;j++)
                {
                    if(h[i+j]!=n[j])
                    {
                        check=false;
                        break;
                    }
                    
                }
            if(check)
            return i;
        }
        return -1;
       
    }
};