class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int freq[26] = {0};

        for(int i = 0; i < p.length(); i++) {
            freq[p[i] - 'a']++;
        }

        int windSize = p.length();

        for(int i = 0; i < s.length(); i++) {

            int windIdx = 0, idx = i;
            int windFreq[26] = {0};

            while(windIdx < windSize && idx < s.length()) {
                windFreq[s[idx] - 'a']++;
                windIdx++;
                idx++;
            }

            if(windIdx == windSize && isFreqSame(freq, windFreq)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};