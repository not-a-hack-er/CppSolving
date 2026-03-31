class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
        return "0";
    string st="";

    for(char c : num) {

        while(!st.empty() && k>0 && st.back() > c) {
            st.pop_back();
            k--;
        }

        st.push_back(c);
    }

    while(k--)
    st.pop_back();

    while(st.size() > 1 && st[0] == '0')
    st.erase(st.begin());

    return st;
    }
};