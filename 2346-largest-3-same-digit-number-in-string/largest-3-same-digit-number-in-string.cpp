class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        int a=-1;
        int n=num.size();
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                if(a<num[i]-'0')
                a=num[i]-'0';
                }
        }
        if(a==-1)
            return "";
        return to_string(a)+to_string(a)+to_string(a);
    }
};