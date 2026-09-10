class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        return "1";
        string s=countAndSay(n-1);
        string res="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int count=1;
            while(i<s.size()-1 && s[i]==s[i+1]){
                count++;
                i++;
            }
            res+=to_string(count)+string(1,ch);
        }
        return res;
    }
};