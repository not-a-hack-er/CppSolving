class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i=0,j=i+k-1;
        unordered_set<string> sp;
        while(j<s.size())
        {
           string c= s.substr(i,k);
           sp.insert(c);
           i++,j++;
        }
        if(sp.size()==(1<<k))
        return true;
        
        return false;
    }
};