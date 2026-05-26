class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> small, capital;
        for(char ch : word) {
            if(islower(ch))
                small.insert(ch);
            else
                capital.insert(tolower(ch));
        }
        int cnt = 0;
        for(char ch : small) {
            if(capital.count(ch))
                cnt++;
        }
        return cnt;
    }
};