class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> small(26, -1), capital(26, -1);

        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if(islower(ch))
                small[ch - 'a'] = i;

            else {

                ch = tolower(ch);

                if(capital[ch - 'a'] == -1)
                    capital[ch - 'a'] = i;
            }
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(small[i] != -1 &&
               capital[i] != -1 &&
               small[i] < capital[i]) {

                cnt++;
            }
        }
        return cnt;
    }
};