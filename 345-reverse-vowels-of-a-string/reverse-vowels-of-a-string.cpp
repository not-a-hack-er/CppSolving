class Solution {
public:
    bool isVowel(char c) {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }

    string reverseVowels(string s) {
        int st = 0, l = s.size() - 1;

        while(st < l) {
            if(isVowel(s[st]) && isVowel(s[l])) {
                swap(s[st], s[l]);
                st++;
                l--;
            }
            else if(!isVowel(s[st])) {
                st++;
            }
            else {
                l--;
            }
        }

        return s;
    }
};