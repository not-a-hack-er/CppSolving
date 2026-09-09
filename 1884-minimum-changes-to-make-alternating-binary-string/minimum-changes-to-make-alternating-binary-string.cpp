class Solution {
public:
    int minOperations(string s) {
        int c1=0,c2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==(i%2)+'0')
                c1++;
             if(s[i]!=(i%2)+'0')           
                c2++;
        }
        return min(c1,c2);
    }
};